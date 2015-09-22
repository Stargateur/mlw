/*
** main.c for main in /home/plasko_a/programation/epitech/mlw
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Mon Nov  3 12:30:47 2014 Antoine Plaskowski
** Last update Wed Sep 23 00:18:25 2015 Antoine Plaskowski
*/

#include	<stdio.h>
#include	<wayland-client.h>
#include	"wayland_typedef.h"
/*
t_event_q	*create_queue(t_display *display)
{
  t_event_q	*event_q;

  if ((event_q = wl_display_create_queue(display)) == NULL)
    {
      fprintf(stdout, "Error can't create a event queue\n");
      return (NULL);
    }
  return (event_q);
}
*/

int		set_global_register(wl_display *display)
{
  static const struct wl_registry_listener registry_listener = {
    .global = NULL,
    .global_remove = NULL
  };
  wl_registry	*registry;

  registry = wl_display_get_registry(display);
  
}

int		main(void)
{
  wl_display	*display;

  if ((display = wl_display_connect(NULL)) == NULL)
    {
      fprintf(stdout, "Error can't open connection with wayland server\n");
      return (1);
    }
  wl_display_disconnect(display);
  return (0);
}
