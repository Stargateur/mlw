/*
** utils.c for utils in /home/plasko_a/projet/epitech/mlw
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Tue Sep 22 22:12:47 2015 Antoine Plaskowski
** Last update Tue Sep 22 23:32:47 2015 Antoine Plaskowski
*/

#include	<stdbool.h>
#include	<string.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	<stdio.h>
#include	<fcntl.h>

static bool	set_cloexec(int fd)
{
  int		flags = fcntl(fd, F_GETFD);

  if (flags == -1)
    return (true);
  if (fcntl(fd, F_SETFD, flags | FD_CLOEXEC) == -1)
    return (true);
  return (false);
}

static int	tmpfile_create_cloexec(char *tmpname)
{
  int		fd = mkstemp(tmpname);

  if (fd == -1 || set_cloexec(fd) == true || unlink(tmpname) == -1)
    {
      perror(NULL);
      close(fd);
      return (-1);
    }
  return (fd);
}

static char	*get_tmpname(void)
{
#define		TEMPLATE_NAME	"/wayland-shared-XXXXXX"
#define		XDG_RUNTIME_DIR	"XDG_RUNTIME_DIR"
  char *	xdg_runtime_dir = getenv(XDG_RUNTIME_DIR);

  if (xdg_runtime_dir == NULL)
  {
    fprintf(stderr, XDG_RUNTIME_DIR " is not set\n");
    return (NULL);
  }
  size_t	size_xdg_runtime_dir = strlen(xdg_runtime_dir);
  size_t	size_tmpname = size_xdg_runtime_dir + sizeof(TEMPLATE_NAME);
  char		*tmpname = malloc(sizeof(*tmpname) * size_tmpname);

  if (tmpname == NULL)
    return (NULL);
  memcpy(tmpname, xdg_runtime_dir, size_xdg_runtime_dir);
  memcpy(tmpname + size_xdg_runtime_dir, TEMPLATE_NAME, sizeof(TEMPLATE_NAME));
  return (tmpname);
#undef	TEMPLATE_NAME
#undef	XDG_RUNTIME_DIR
}

int	create_anon_file(off_t size)
{
  char	*tmpname = get_tmpname();

  if (tmpname == NULL)
    return (-1);
  int	fd = tmpfile_create_cloexec(tmpname);

  free(tmpname);
  if (fd == -1)
    return (-1);
  if (ftruncate(fd, size) == -1)
    {
      perror(NULL);
      close(fd);
      return (-1);
    }
  return (fd);
}

