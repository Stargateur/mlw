/*
** window.c for window in /home/plasko_a/projet/epitech/mlw
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Wed Sep 23 00:35:20 2015 Antoine Plaskowski
** Last update Wed Sep 23 05:18:07 2015 Antoine Plaskowski
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	<stdint.h>
#include	<wayland-client.h>
#include	"window.h"

static void shell_surface_listener_handle_ping(void *data, wl_shell_surface *shell_surface, uint32_t serial)
{
  wl_shell_surface_pong(shell_surface, serial);
  (void)data;
}

static void shell_surface_listener_handle_configure(void *data, wl_shell_surface *shell_surface, uint32_t edges, int32_t width, int32_t height)
{
  (void)data;
  (void)shell_surface;
  (void)edges;
  (void)width;
  (void)height;
}

static void shell_surface_listener_handle_popup_done(void *data, wl_shell_surface *shell_surface)
{
  (void)data;
  (void)shell_surface;
}

static const wl_shell_surface_listener shell_surface_listener = {
  .ping = &shell_surface_listener_handle_ping,
  .configure = &shell_surface_listener_handle_configure,
  .popup_done = &shell_surface_listener_handle_popup_done,
};

t_window	*create_window(wl_compositor *compositor, wl_shell *shell, char *title)
{
  if (compositor == NULL || shell == NULL)
    return (NULL);

  t_window	*window = malloc(sizeof(*window));

  if (window == NULL)
    {
      perror("malloc");
      return (NULL);
    }
  window->compositor = compositor;
  window->shell = shell;

  window->surface = wl_compositor_create_surface(window->compositor);
  if (window->surface == NULL)
    {
      perror("wl_compositor_create_surface");
      free(window);
      return (NULL);
    }

  window->shell_surface = wl_shell_get_shell_surface(shell, window->surface);
  if (window->shell_surface == NULL)
    {
      perror("wl_shell_get_shell_surface");
      free(window);
      return (NULL);
    }
  wl_shell_surface_set_toplevel(window->shell_surface);
  if (title != NULL)
    wl_shell_surface_set_title(window->shell_surface, title);
  wl_shell_surface_add_listener(window->shell_surface, &shell_surface_listener, window);
  return (window);
}

void	free_window(t_window *window)
{
  if (window != NULL)
    {
      free(window);
    }
}
