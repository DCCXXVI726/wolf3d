/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thorker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 16:58:16 by thorker           #+#    #+#             */
/*   Updated: 2019/03/07 15:16:17 by thorker          ###   ########.fr       */
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
typedef struct  s_player
{
	double      x;
	double      y;
	double      angle;
}               t_player;

typedef	struct	s_wolf
{
	struct timeval			time;
	struct timeval			old_time;
	int			win_heidth;
	int			win_width;
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img1_ptr;
	char		*start_img1;
	int			bpp;
	int			size_line;
	int			endian;
	t_opencl	*ft_opencl;
	size_t		limit;
	t_player	*player;
	int			width;
	int			heigth;
	char		*map;
	cl_mem		cl_map;
	int			iteration;
	double		fov;
	int			mouse_x;
	double		step;
	int			step_count;
	char		move_forward;
	char		move_back;
	char		move_right;
	char		move_left;
	int			line_horizon;
	double		step_ill;
	void		*img_ptr_tx;
	int			bpp_tx;
	int			size_line_tx;
	int			endian_tx;
	char		*start_img_tx;
	int			width_tx;
	int			heigth_tx;
	void        *img_ptr_tx2;
	int         bpp_tx2;
	int         size_line_tx2;
	int         endian_tx2;
	char        *start_img_tx2;
	int         width_tx2;
	int         heigth_tx2;
	void        *img_ptr_tx3;
	int         bpp_tx3;
	int         size_line_tx3;
	int         endian_tx3;
	char        *start_img_tx3;
	int         width_tx3;
	int         heigth_tx3;
}				t_wolf;

int				put_img(t_wolf *wolf);
t_wolf			*create_struct();
void    		hook(t_wolf *wolf);
int     		key_press(int key, t_wolf *wolf);
int             key_release(int key, t_wolf *wolf);
void			put_player(t_wolf *wolf);
int     		mouse_move(int x, int y, t_wolf *wolf);
#endif
