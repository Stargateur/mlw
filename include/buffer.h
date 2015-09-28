/*
** buffer.h for buffer in /home/plasko_a/projet/epitech/mlw
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Tue Sep 22 23:53:23 2015 Antoine Plaskowski
** Last update Mon Sep 28 06:29:25 2015 Antoine Plaskowski
*/

#ifndef		BUFFER_H_
# define	BUFFER_H_

#include	"wayland_typedef.h"

typedef	struct	s_buffer	t_buffer;

struct		s_buffer
{
  wl_shm	*shm;
  wl_buffer	*buffer;
  uint32_t	*data;
  size_t	width;
  size_t	height;
  size_t	stride;
  size_t	size;
  int		fd;
};

t_buffer	*create_buffer(wl_shm *shm, size_t width, size_t height);
void		free_buffer(t_buffer *buffer);

#endif		/* !BUFFER_H_ */
