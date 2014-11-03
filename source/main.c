/*
** main.c for main in /home/plasko_a/programation/epitech/mlw
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Mon Nov  3 12:30:47 2014 Antoine Plaskowski
** Last update Mon Nov  3 15:23:27 2014 Antoine Plaskowski
*/

#include	<stdio.h>
#include	<wayland-client.h>
#include	"my_typedef.h"

int		main(void)
{
  t_display	*display;
  t_event_q	*event_q;

  if ((display = wl_display_connect(NULL)) == NULL)
    {
      fprintf(stdout, "Error can't open connection with wayland server\n");
      return (1);
    }
  if ((event_q = wl_display_create_queue(display)) == NULL)
    {
      fprintf(stdout, "Error can't create a event queue\n");
      return (1);      
    }
  printf("%d", wl_display_get_fd(display));
  wl_event_queue_destroy(event_q);
  wl_display_disconnect(display);
  return (0);
}
