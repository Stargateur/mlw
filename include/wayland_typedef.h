/*
** my_wayland_typedef.h for my_wayland_typedef in /home/plasko_a/programation/epitech/mlw
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Mon Nov  3 15:07:22 2014 Antoine Plaskowski
** Last update Wed Sep 23 01:20:39 2015 Antoine Plaskowski
*/

#ifndef		MY_WAYLAND_TYPEDEF_H_
# define	MY_WAYLAND_TYPEDEF_H_

# include	<wayland-client.h>

typedef	struct	wl_display	wl_display;
typedef	struct	wl_event_queue	wl_event_q;
typedef	struct	wl_registry	wl_registry;
typedef	struct	wl_shm		wl_shm;
typedef	struct	wl_buffer	wl_buffer;
typedef	struct	wl_compositor	wl_compositor;
typedef	struct	wl_callback	wl_callback;
typedef	struct	wl_shell	wl_shell;
typedef	struct	wl_surface	wl_surface;
typedef	struct	wl_shell_surface	wl_shell_surface;
typedef	struct	wl_shell_surface_listener	wl_shell_surface_listener;

#endif		/* !MY_WAYLAND_TYPEDEF_H_ */
