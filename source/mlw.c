/*
** mlw.c for mlw in /home/plasko_a/programation/epitech/mlw
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Mon Nov  3 12:30:47 2014 Antoine Plaskowski
** Last update Wed Sep 23 03:06:44 2015 Antoine Plaskowski
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>
#include	<wayland-client.h>
#include	"wayland_typedef.h"
#include	"mlw.h"

static void	registry_handle_global(void *data, struct wl_registry *registry,
				       uint32_t id, const char *interface,
				       uint32_t version)
{
  t_mlw		 *mlw = data;

  if (strcmp(interface, "wl_compositor") == 0)
      mlw->compositor = wl_registry_bind(registry, id, &wl_compositor_interface, version);
  else if (strcmp(interface, "wl_shm") == 0)
      mlw->shm = wl_registry_bind(registry, id, &wl_shm_interface, version);
  else if (strcmp(interface, "wl_shell") == 0)
      mlw->shell = wl_registry_bind(registry, id, &wl_shell_interface, version);
}

static void registry_handle_global_remove(void *data, struct wl_registry *registry,
					  uint32_t id)
{
  (void)data;
  (void)registry;
  (void)id;
}

static const struct wl_registry_listener registry_listener = {
  .global = registry_handle_global,
  .global_remove = registry_handle_global_remove
};

t_mlw		*create_mlw(void)
{
  t_mlw		*mlw = malloc(sizeof(*mlw));

  if (mlw == NULL)
    return (NULL);
  if ((mlw->display = wl_display_connect(NULL)) == NULL)
    {
      fprintf(stdout, "Error can't open connection with wayland server\n");
      free(mlw);
      return (NULL);
    }
  wl_registry_add_listener(wl_display_get_registry(mlw->display), &registry_listener, mlw);
  wl_display_dispatch(mlw->display);
  wl_display_roundtrip(mlw->display);
  return (mlw);
}

void		free_mlx(t_mlw *mlw)
{
  wl_display_disconnect(mlw->display);
}
