/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfalmer- <bfalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 13:58:41 by thorker           #+#    #+#             */
/*   Updated: 2019/03/11 19:39:43 by bfalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int			get_p2(t_wolf *wolf, t_orientation *orientation, double *p, double *pos)
{
	double	p1;
	double	pos1;

	orientation->orientation = 0;
	if (sin(orientation->angle) > 0)
	{
		orientation->y = (int)wolf->player->y;
		orientation->y_step = 1;
		orientation->x = wolf->player->x + (wolf->player->y - (int)(wolf->player->y)) / tan(orientation->angle);
	}
	else
	{
		orientation->y = 1 + (int)wolf->player->y;
		orientation->y_step = -1;
		orientation->x = wolf->player->x - (1 - wolf->player->y + (int)(wolf->player->y)) / tan(orientation->angle);
	}
	orientation->x_step = orientation->y_step / tan(orientation->angle);
	find_orientation_p2(orientation, wolf);
	p1 = 0;
	if (orientation->orientation!= 0)
	{
		p1 = (orientation->x - wolf->player->x) * cos(wolf->player->angle) +
			(wolf->player->y - orientation->y) * sin(wolf->player->angle);
		pos1 = orientation->x - (int)orientation->x;
	}
	if (*p == 0 || (p1 != 0 && p1 < *p))
	{
		*p = p1;
		*pos = pos1;
		orientation->angle = orientation->orientation;
		return (1);
	}
	else
		return (0);
}

static void	get_p(t_wolf *wolf, t_main_window *window)
{
	t_orientation *orientation;

	orientation = (t_orientation*)malloc(sizeof(t_orientation));
	orientation->angle = wolf->player->angle + wolf->fov[(int)(wolf->fov[0])] * (1.0 / 2 - ((double)(window->i)) / wolf->iteration);
	if (cos(orientation->angle) > 0)
	{
		orientation->x = 1 + (int)(wolf->player->x);
		orientation->x_step = 1;
		orientation->y = wolf->player->y - (1 + (int)(wolf->player->x) - wolf->player->x) * tan(orientation->angle);
	}
	else
	{
		orientation->x = (int)wolf->player->x;
		orientation->x_step = -1;
		orientation->y = wolf->player->y + (wolf->player->x - (int)(wolf->player->x)) * tan(orientation->angle);
	}
	orientation->y_step = orientation->x_step * tan(orientation->angle);
	find_orientation_p(orientation, wolf);
	window->p = 0;
	if (wolf->orientation != 0)
	{
		window->p = (orientation->x - wolf->player->x) * cos(wolf->player->angle) +
			(wolf->player->y - orientation->y) * sin(wolf->player->angle);
		window->pos = orientation->y - (int)orientation->y;
	}
	if (get_p2(wolf, orientation, &window->p, &window->pos) == 1)
		wolf->orientation = (int)orientation->angle;
}

static void		draw_hands(t_wolf *wolf)
{
	double	x;
	double	y;
	int		new_x;
	int		new_y;
	int		color;

	y = -1;
	while (++y < wolf->win_heidth / 2)
	{
		new_y = y / (wolf->win_heidth / 2) * (wolf->tx + 2)->heidth;
		x = -1;
		while (++x < wolf->win_width / 3)
		{
			new_x = x / (wolf->win_width / 3) * (wolf->tx + 2)->width;
			if (((int*)(wolf->tx + 2)->start_img)[new_y *
				(wolf->tx + 2)->width + new_x] != 0xFFFFFF)
			{
				color = ((int*)(wolf->tx + 2)->start_img)[new_y *
					(wolf->tx + 2)->width + new_x];
				((int*)wolf->start_img)[(int)(((y + wolf->win_heidth / 2) *
					wolf->win_width) +
						(x + wolf->win_width / 100 * 45))] = color;
			}
		}
	}
}

static void	main_window(t_wolf *wolf, t_main_window *window)
{
	while (++(window->i) < wolf->iteration)
	{
		wolf->orientation = 0;
		get_p(wolf, window);
		if (window->p != 0)
			window->p = fabs(1500 / window->p);
		window->y = -1;
		define_wall(wolf);
		window->pos = (int)(window->pos * (wolf->curr_tx)->width);
		while (++(window->y) < wolf->win_heidth)
		{
			define_color(wolf, window);
			window->x = (double)window->i * wolf->win_width / wolf->iteration;
			while (window->x < (window->i + 1) *
				(double)wolf->win_width / wolf->iteration &&
					window->x < wolf->win_width)
			{
				((int*)wolf->start_img)[(int)(window->y *
					wolf->win_width + window->x)] = window->color;
				window->x++;
			}
		}
	}
	draw_hands(wolf);
}

int			put_img(t_wolf *wolf)
{
	t_main_window *window;

	if ((window = (t_main_window*)malloc(sizeof(t_main_window))) == 0)
		check_error_n_exit(1, "Didn't create window sctruct");
	window->i = 0;
	if (wolf->menu == 0)
	{
		moving(wolf);
		main_window(wolf, window);
	}
	else
		menu(wolf);
	wolf->old_time = wolf->time;
	mlx_put_image_to_window(wolf->mlx_ptr, wolf->win_ptr, wolf->img_ptr, 0, 0);
	add_text(wolf);
	put_fps(wolf);
	return (0);
}
