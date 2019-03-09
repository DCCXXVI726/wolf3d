/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thorker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 13:58:41 by thorker           #+#    #+#             */
/*   Updated: 2019/03/09 18:12:54 by thorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	put_fps(t_wolf *wolf)
{
	wolf->old_time = wolf->time;
	gettimeofday(&wolf->time, NULL);
	if (wolf->time.tv_sec > wolf->old_time.tv_sec)
		mlx_string_put(wolf->mlx_ptr, wolf->win_ptr, 0, 0, 0xFF0000,
				ft_itoa(((int)(1000000 / (wolf->time.tv_usec + 1000000 -
								wolf->old_time.tv_usec)))));
	else
		mlx_string_put(wolf->mlx_ptr, wolf->win_ptr, 0, 0, 0xFF0000,
				ft_itoa(((int)(1000000 / (wolf->time.tv_usec -
								wolf->old_time.tv_usec)))));
}

int	get_p2(t_wolf *wolf, double *angle, double *p, double *pos)
{
	int orientation;
	double x2;
	double y2;
	double p1;
	double pos1;
	double x_step;
	double y_step;

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

double	get_p(t_wolf *wolf, int i, int *orientation, double *pos)
{
	double	x1;
	double	y1;
	double	angle;
	double 	p;
	double	x_step;
	double	y_step;

	angle = wolf->player->angle + wolf->fov * (1.0/ 2 - ((double)i) / wolf->iteration);
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
		p = (x1 - wolf->player->x) * cos(wolf->player->angle) + (wolf->player->y - y1) * sin(wolf->player->angle);
		*pos = y1 - (int)y1;
	}
	if (get_p2(wolf, &angle, &p, pos) == 1)
		*orientation = (int)angle;
	return (p);
}

int	put_img(t_wolf *wolf)
{
	int	i;
	double x1;
	double y1;
	double p;
	int color;
	int orientation;
	double pos;

	if (wolf->menu == 0)
	{
		moving(wolf);
		i = 0;
		while (i < wolf->iteration)
		{
			orientation = 0;
			p = get_p(wolf, i, &orientation, &pos);
			if (p != 0)
				p = fabs(900 / p);
			y1 = 0;
			if (orientation == 1)
				wolf->curr_tx = wolf->tx;
			else if (orientation == 2)
				wolf->curr_tx = wolf->tx + 1;
			else if (orientation == 3)
				wolf->curr_tx = wolf->tx + 3;
			else
				wolf->curr_tx = wolf->tx + 4;
			pos = (int)(pos * (wolf->curr_tx)->width);
			while (y1 < wolf->win_heidth)
			{
				if (y1 < wolf->line_horizon - p / 2)
					color = 0xFFFFFF;	
				else if (y1 < wolf->line_horizon + p / 2)
					color = ((int*)wolf->curr_tx->start_img)[(int)pos + (int)((y1 - wolf->line_horizon + p / 2) / p * wolf->curr_tx->heidth) * wolf->curr_tx->width];
				else
					color = 0x666666;
				x1 = (double)i * wolf->win_width / wolf->iteration;
				while (x1 < (i + 1) * (double) wolf->win_width / wolf->iteration && x1 < wolf->win_width)
				{
					((int*)wolf->start_img)[((int)y1) * wolf->win_width + ((int)x1)] = color;
					x1++;
				}
				y1++;
			}
			i++;
		}
		y1 = 0;
		x1 = 0;
		while (y1 < wolf->win_heidth / 2)
		{
			while (y1 < wolf->win_heidth / 2)
			{
				
				int new_y = y1 / (wolf->win_heidth / 2) * (wolf->tx + 2)->heidth;
				while (x1 < wolf->win_width / 3)
				{
					int new_x = x1 / (wolf->win_width / 3) * (wolf->tx + 2)->width ;
					if (((int*)(wolf->tx + 2)->start_img)[new_y * (wolf->tx + 2)->width + new_x] != 0xFFFFFF)
					{
						color = ((int*)(wolf->tx + 2)->start_img)[new_y * (wolf->tx + 2)->width + new_x] ;
						((int*)wolf->start_img)[(int)(((y1 + wolf->win_heidth / 2) * wolf->win_width) + (x1 + wolf->win_width / 3))] = color;
					}
					x1++;
				}
				x1 = 0;
				y1++;
			}
		}
	}
	else
		menu(wolf);
	wolf->old_time = wolf->time;
	gettimeofday(&wolf->time, NULL);
	mlx_put_image_to_window(wolf->mlx_ptr, wolf->win_ptr, wolf->img_ptr, 0, 0);
	
	if (wolf->time.tv_sec > wolf->old_time.tv_sec)
		mlx_string_put(wolf->mlx_ptr, wolf->win_ptr, 0, 0, 0xFF0000, ft_itoa(((int)(1000000 / (wolf->time.tv_usec + 1000000 - wolf->old_time.tv_usec)))));
	else
		mlx_string_put(wolf->mlx_ptr, wolf->win_ptr, 0, 0, 0xFF0000, ft_itoa(((int)(1000000 / (wolf->time.tv_usec - wolf->old_time.tv_usec)))));
			return (0);
	mlx_put_image_to_window(wolf->mlx_ptr, wolf->win_ptr, wolf->img_ptr, 0, 0);
	put_fps(wolf);
	return (0);
}
