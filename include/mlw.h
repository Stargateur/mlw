/*
** mlw.h for mlw in /home/plasko_a/projet/epitech/mlw
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Wed Sep 23 02:43:36 2015 Antoine Plaskowski
** Last update Wed Sep 23 03:55:37 2015 Antoine Plaskowski
*/

#ifndef		MLW_H_
# define	MLW_H_

# include	"wayland_typedef.h"

typedef	struct	s_mlw	t_mlw;

struct		s_mlw
{
  wl_display	*display;
  wl_compositor	*compositor;
  wl_shm	*shm;
  wl_shm	*shell;
};

t_mlw		*create_mlw(void);
void		free_mlw(t_mlw *mlw);

#endif		/* !MLW_H_ */
