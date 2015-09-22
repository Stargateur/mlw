/*
** buffer.h for buffer in /home/plasko_a/projet/epitech/mlw
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Tue Sep 22 23:53:23 2015 Antoine Plaskowski
** Last update Wed Sep 23 00:20:33 2015 Antoine Plaskowski
*/

#ifndef		BUFFER_H_
# define	BUFFER_H_

#include	"wayland_typedef.h"

typedef	struct	s_buffer	t_buffer;

struct		s_buffer
{
  wl_shm	*shm;
  wl_buffer	*buffer;
  void		*data;
  size_t	width;
  size_t	height;
  size_t	stride;
  size_t	size;
  int		fd;
};

#endif		/* !BUFFER_H_ */
