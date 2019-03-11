/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfalmer- <bfalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 13:58:41 by thorker           #+#    #+#             */
/*   Updated: 2019/03/11 17:38:47 by bfalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int			get_p2(t_wolf *wolf, double *angle, double *p, double *pos)
{
	int		orientation;
	double	x2;
	double	y2;
	double	p1;
	double	pos1;
	double	x_step;
	double	y_step;

	orientation = 0;
	if (sin(*angle) > 0)
	{
		y2 = (int)wolf->player->y;
		y_step = 1;
		x2 = wolf->player->x + (wolf->player->y - (int)(wolf->player->y)) / tan(*angle);
	}
	else
	{
		y2 = 1 + (int)wolf->player->y;
		y_step = -1;
		x2 = wolf->player->x - (1 - wolf->player->y + (int)(wolf->player->y)) / tan(*angle);
	}
	x_step = y_step / tan(*angle);
	while (x2 >= 0 && x2 < wolf->width && y2 >= 0 && y2 < wolf->heigth && orientation == 0)
	{
		if (*(wolf->map + (int)(x2) + ((int)y2 - 1) * wolf->width) != '0')
		{
			orientation = 2;
			break ;
		}
		if (*(wolf->map + (int)(x2) + ((int)y2) * wolf->width) != '0')
		{
			orientation = 4;
			break ;
		}
		y2 = y2 - y_step;
		x2 = x2 + x_step;
	}
	p1 = 0;
	if (orientation != 0)
	{
		p1 = (x2 - wolf->player->x) * cos(wolf->player->angle) + (wolf->player->y - y2) * sin(wolf->player->angle);
		pos1 = x2 - (int)x2;
	}
	if (*p == 0 || (p1 != 0 && p1 < *p))
	{
		*p = p1;
		*pos = pos1;
		*angle = orientation;
		return (1);
	}
	else
		return (0);
}

static double	get_p(t_wolf *wolf, int i, int *orientation, double *pos)
{
	double	x1;
	double	y1;
	double	angle;
	double	p;
	double	x_step;
	double	y_step;

	angle = wolf->player->angle + wolf->fov[(int)(wolf->fov[0])] * (1.0 / 2 - ((double)i) / wolf->iteration);
	if (cos(angle) > 0)
	{
		x1 = 1 + (int)(wolf->player->x);
		x_step = 1;
		y1 = wolf->player->y - (1 + (int)(wolf->player->x) - wolf->player->x) * tan(angle);
	}
	else
	{
		x1 = (int)wolf->player->x;
		x_step = -1;
		y1 = wolf->player->y + (wolf->player->x - (int)(wolf->player->x)) * tan(angle);
	}
	y_step = x_step * tan(angle);
	while (x1 >= 0 && x1 < wolf->width && y1 >= 0 && y1 < wolf->heigth && *orientation == 0)
	{
		if (*(wolf->map + ((int)(x1)) + (((int)y1)) * wolf->width) != '0')
		{
			*orientation = 3;
			break;
		}
		if (*(wolf->map + ((int)(x1 - 1)) + (((int)y1)) * wolf->width) != '0')
		{
			*orientation = 1;
			break;
		}
		y1 = y1 - y_step;
		x1 = x1 + x_step;
	}
	p = 0;
	if (*orientation != 0)
	{
		p = (x1 - wolf->player->x) * cos(wolf->player->angle) +
		(wolf->player->y - y1) * sin(wolf->player->angle);
		*pos = y1 - (int)y1;
	}
	if (get_p2(wolf, &angle, &p, pos) == 1)
		*orientation = (int)angle;
	return (p);
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

static void	define_wall(t_wolf *wolf)
{
	if (wolf->orientation == 1)
		wolf->curr_tx = wolf->tx;
	else if (wolf->orientation == 2)
		wolf->curr_tx = wolf->tx + 1;
	else if (wolf->orientation == 3)
		wolf->curr_tx = wolf->tx + 3;
	else
		wolf->curr_tx = wolf->tx + 4;
}

static void	define_color(t_wolf *wolf, t_main_window *window)
{
	if (window->y < wolf->line_horizon - window->p / 2)
		window->color = 0xFFFFFF;
	else if (window->y < wolf->line_horizon + window->p / 2)
		window->color = ((int*)wolf->curr_tx->start_img)[(int)window->pos +
			(int)((window->y - wolf->line_horizon + window->p / 2) /
				window->p * wolf->curr_tx->heidth) * wolf->curr_tx->width];
	else
		window->color = 0x666666;
}

static void	main_window(t_wolf *wolf, t_main_window *window)
{
	while (++(window->i) < wolf->iteration)
	{
		wolf->orientation = 0;
		window->p = get_p(wolf, window->i, &wolf->orientation, &window->pos);
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
