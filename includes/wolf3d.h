/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfalmer- <bfalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 16:58:16 by thorker           #+#    #+#             */
/*   Updated: 2019/03/11 20:19:01 by bfalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H
# include "libft.h"
# include <mlx.h>
# include <math.h>
# include <time.h>
# include <sys/time.h>
# define ANGLE 3.14 / 200
# define TIME 1000000

typedef struct		s_player
{
	double			x;
	double			y;
	double			angle;
}					t_player;

typedef struct		s_texture
{
	void			*img_ptr;
	void			*start_img;
	int				bpp;
	int				size_line;
	int				endian;
	int				heidth;
	int				width;
}					t_texture;

typedef struct		s_main_window
{
	int				i;
	double			x;
	double			y;
	double			p;
	int				color;
	double			pos;
	double			p2;
	double			pos2;
}					t_main_window;

typedef struct		s_orientation
{
	double			x;
	double			y;
	double			angle;
	double			x_step;
	double			y_step;
	int				orientation;
}					t_orientation;

typedef	struct		s_wolf
{
	struct timeval	time;
	struct timeval	old_time;
	int				win_heidth;
	int				win_width;
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	char			*start_img;
	int				bpp;
	int				size_line;
	int				endian;
	size_t			limit;
	t_player		*player;
	int				width;
	int				heigth;
	char			*map;
	cl_mem			cl_map;
	int				iteration;
	int				mouse_x;
	double			step;
	int				step_count;
	char			move_forward;
	char			move_back;
	char			move_right;
	char			move_left;
	int				line_horizon;
	double			step_ill;
	t_texture		*tx;
	t_texture		*curr_tx;
	int				menu;
	int				menu_string;
	double			*fov;
	int				*mouse_speed;
	int				orientation;
}					t_wolf;

void				moving(t_wolf *wolf);
int					put_img(t_wolf *wolf);
t_wolf				*create_struct();
void				hook(t_wolf *wolf);
int					key_press(int key, t_wolf *wolf);
int					key_release(int key, t_wolf *wolf);
void				put_player(t_wolf *wolf);
int					mouse_move(int x, int y, t_wolf *wolf);
void				menu(t_wolf *wolf);
int					add_text(t_wolf *wolf);
void				define_wall(t_wolf *wolf);
void				define_color(t_wolf *wolf, t_main_window *window);
void				find_orientation_p(t_orientation *orientation,
										t_wolf *wolf);
void				find_orientation_p2(t_orientation *orientation,
										t_wolf *wolf);
void				get_p(t_wolf *wolf, t_main_window *window);
#endif
