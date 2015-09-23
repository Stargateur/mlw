/*
** utils.c for utils in /home/plasko_a/projet/epitech/mlw
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Tue Sep 22 22:12:47 2015 Antoine Plaskowski
** Last update Wed Sep 23 04:20:38 2015 Antoine Plaskowski
*/

#include	<wayland-client.h>
#include	<stdbool.h>
#include	<string.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	<stdio.h>
#include	<fcntl.h>
#include	<sys/mman.h>
#include	"buffer.h"

static bool	set_cloexec(int fd)
{
  int		flags = fcntl(fd, F_GETFD);

  if (flags == -1)
    {
      perror("fcntl");
      return (true);
    }
  if (fcntl(fd, F_SETFD, flags | FD_CLOEXEC) == -1)
    {
      perror("fcntl");
      return (true);
    }
  return (false);
}

static int	tmpfile_create_cloexec(char *tmpname)
{
  int		fd = mkstemp(tmpname);

  if (fd == -1)
    {
      perror("mkstemp");
      close(fd);
      return (-1);
    }
  if (set_cloexec(fd) == true)
    {
      close(fd);
      return (-1);
    }
  if (unlink(tmpname) == -1)
    {
      perror("unlink");
      close(fd);
      return (-1);
    }
  return (fd);
}

static char	*get_tmpname(void)
{
#define		TEMPLATE_NAME	"/wayland-shared-XXXXXX"
#define		XDG_RUNTIME_DIR	"XDG_RUNTIME_DIR"
  char		*xdg_runtime_dir = getenv(XDG_RUNTIME_DIR);

  if (xdg_runtime_dir == NULL)
  {
    fprintf(stderr, XDG_RUNTIME_DIR " is not set\n");
    return (NULL);
  }
  size_t	size_xdg_runtime_dir = strlen(xdg_runtime_dir);
  size_t	size_tmpname = size_xdg_runtime_dir + sizeof(TEMPLATE_NAME);
  char		*tmpname = malloc(sizeof(*tmpname) * size_tmpname);

  if (tmpname == NULL)
    {
      perror("malloc");
      return (NULL);
    }
  memcpy(tmpname, xdg_runtime_dir, size_xdg_runtime_dir);
  memcpy(tmpname + size_xdg_runtime_dir, TEMPLATE_NAME, sizeof(TEMPLATE_NAME));
  return (tmpname);
#undef	TEMPLATE_NAME
#undef	XDG_RUNTIME_DIR
}

static int	create_anon_file(off_t size)
{
  char		*tmpname = get_tmpname();

  if (tmpname == NULL)
    return (-1);
  int		fd = tmpfile_create_cloexec(tmpname);

  free(tmpname);
  if (fd == -1)
    return (-1);
  if (ftruncate(fd, size) == -1)
    {
      perror("ftruncate");
      close(fd);
      return (-1);
    }
  return (fd);
}

t_buffer	*create_buffer(wl_shm *shm, size_t width, size_t height)
{
  t_buffer	*buffer = malloc(sizeof(*buffer));

  if (buffer == NULL)
    return (NULL);
  buffer->width = width;
  buffer->height = height;
  buffer->stride = buffer->width * 4;
  buffer->size = buffer->stride * buffer->height;

  buffer->fd = create_anon_file((off_t)buffer->size);
  if (buffer->fd == -1)
    {
      fprintf(stderr, "Cannot create a buffer file of size %lu.\n", buffer->size);
      free(buffer);
      return (NULL);
    }

  buffer->data = mmap(NULL, buffer->size, PROT_READ | PROT_WRITE, MAP_SHARED, buffer->fd, 0);
  if (buffer->data == MAP_FAILED)
    {
      perror("mmap");
      close(buffer->fd);
      free(buffer);
      return (NULL);
    }

  struct wl_shm_pool *pool = wl_shm_create_pool(shm, buffer->fd, (int32_t)buffer->size);
  buffer->buffer = wl_shm_pool_create_buffer(pool, 0, (int32_t)buffer->width, (int32_t)buffer->height,
					     (int32_t)buffer->stride, WL_SHM_FORMAT_XRGB8888);

  wl_shm_pool_destroy(pool);
  return (buffer);
}

void		free_buffer(t_buffer *buffer)
{
  if (buffer != NULL)
    {
      if (munmap(buffer->data, buffer->size) == -1)
	perror("munmap");
      if (close(buffer->fd) == -1)
	perror("close");
    }
}
