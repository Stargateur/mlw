/*
** window.h for window in /home/plasko_a/projet/epitech/mlw
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Wed Sep 23 01:00:44 2015 Antoine Plaskowski
** Last update Wed Sep 23 02:29:26 2015 Antoine Plaskowski
*/

#ifndef		WINDOW_H_
# define	WINDOW_H_

# include	"wayland_typedef.h"
# include	"buffer.h"

typedef	struct	s_window	t_window;

struct		s_window
{
  wl_compositor	*compositor;
  wl_shell	*shell;
  wl_surface	*surface;
  wl_shell_surface	*shell_surface;
  void		(*espose)(void *data);
  void		*data;
};

#endif		/* !WINDOW_H_ */
