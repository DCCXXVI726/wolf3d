/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfalmer- <bfalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 17:42:34 by thorker           #+#    #+#             */
/*   Updated: 2019/02/15 15:27:09 by bfalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H
# include "../libft/libft.h"
# include <mlx.h>
# include <math.h>
# define ANGLE 0.1
# define STEP 0.5

typedef struct  s_player
{
	double      x;
	double      y;
	double      angle;
}               t_player;

typedef	struct	s_wolf
{
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
}				t_wolf;

int				put_img(t_wolf *wolf);
t_wolf			*create_struct();
void    		hook(t_wolf *wolf);
int     		key_press(int key, t_wolf *wolf);
void			put_player(t_wolf *wolf);
#endif
