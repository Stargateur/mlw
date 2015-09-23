/*
** frame.h for frame in /home/plasko_a/projet/epitech/mlw
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Wed Sep 23 06:22:03 2015 Antoine Plaskowski
** Last update Wed Sep 23 06:31:14 2015 Antoine Plaskowski
*/

#ifndef		FRAME_H_
# define	FRAME_H_

#include	"window.h"
#include	"buffer.h"

typedef	struct	s_frame	t_frame;

struct		s_frame
{
  t_window	*window;
  t_buffer	*buffer;
  void		(*fct)(t_frame *frame);
  void		*data;
};

t_frame		*create_frame(t_window *window, t_buffer *buffer, void (*fct)(t_frame *data), void *data);

#endif		/* !FRAME_H_ */
