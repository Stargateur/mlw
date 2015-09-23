/*
** window.h for window in /home/plasko_a/projet/epitech/mlw
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Wed Sep 23 01:00:44 2015 Antoine Plaskowski
** Last update Wed Sep 23 03:52:55 2015 Antoine Plaskowski
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
};

t_window	*create_window(wl_compositor *compositor, wl_shell *shell, char *title);
void		free_window(t_window *window);
void		put_buffer_to_window(t_window *window, t_buffer *buffer);

#endif		/* !WINDOW_H_ */
