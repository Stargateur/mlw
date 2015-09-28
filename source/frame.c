/*
** frame.c for frame in /home/plasko_a/projet/epitech/mlw
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Wed Sep 23 05:18:11 2015 Antoine Plaskowski
** Last update Mon Sep 28 06:01:01 2015 Antoine Plaskowski
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	"frame.h"

static const struct wl_callback_listener frame_listener;
static void frame_listener_handle_done(void *data, struct wl_callback *callback, uint32_t time)
{
  t_frame       *frame = data;

  (void)time;
  wl_callback_destroy(callback);
  if (frame->fct != NULL)
    frame->fct(frame);
  wl_surface_damage(frame->window->surface, 0, 0, (int32_t)frame->buffer->width, (int32_t)frame->buffer->height);
  wl_surface_attach(frame->window->surface, frame->buffer->buffer, 0, 0);
  wl_callback_add_listener(wl_surface_frame(frame->window->surface), &frame_listener, frame);
  wl_surface_commit(frame->window->surface);  
}

static const struct wl_callback_listener frame_listener = {
  .done = frame_listener_handle_done,
};

t_frame		*create_frame(t_window *window, t_buffer *buffer, void (*fct)(t_frame *data), void *data)
{
  if (window == NULL || buffer == NULL || fct == NULL)
    return (NULL);
  t_frame	*frame = malloc(sizeof(*frame));

  if (frame == NULL)
    {
      perror("malloc");
      return (NULL);
    }
  frame->window = window;
  frame->buffer = buffer;
  frame->fct = fct;
  frame->data = data;
  wl_surface_attach(frame->window->surface, frame->buffer->buffer, 0, 0);
  wl_callback_add_listener(wl_surface_frame(frame->window->surface), &frame_listener, frame);
  wl_surface_commit(frame->window->surface);  
  return (frame);
}
