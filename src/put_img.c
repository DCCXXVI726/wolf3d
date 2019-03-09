/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thorker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 13:58:41 by thorker           #+#    #+#             */
/*   Updated: 2019/03/09 15:53:05 by thorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		put_img(t_wolf *wolf)
{
	double angle;
	int	i;
	double x1;
	double x2;
	double y1;
	double y2;
	double x_step;
	double y_step;
	double p;
	int color;
	int color_wall;
	double pos;

	if (wolf->menu == 0)
	{
		moving(wolf);
		i = 0;
		while (i < wolf->iteration)
		{
			angle = wolf->player->angle + wolf->fov * (1.0/ 2 - ((double)i) / wolf->iteration);
			if (cos(angle) != 0)
			{
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
				while (x1 >= 0 && x1 < wolf->width && y1 >= 0 && y1 < wolf->heigth)
				{
					if (*(wolf->map + ((int)(x1)) + (((int)y1)) * wolf->width) != '0')
						break ;
					if (*(wolf->map + ((int)(x1 - 1)) + (((int)y1)) * wolf->width) != '0')
						break ;
					y1 = y1 - y_step;
					x1 = x1 + x_step;
				}
			}
			else
			{
				x1 = -1;
				y1 = -1;
			}
			if (sin(angle) != 0)
			{
				if (sin(angle) > 0)
				{
					y2 = (int)wolf->player->y;
					y_step = 1;
					if (cos(angle) != 0)
					{
						x2 = wolf->player->x + (wolf->player->y - (int)(wolf->player->y)) / tan(angle);
						x_step = y_step / tan(angle);
					}
					else
					{
						x2 = (int)wolf->player->x;
						x_step = 0;
					}
				}
				else
				{
					y2 = 1 + (int)wolf->player->y;
					y_step = -1;
					if (cos(angle) != 0)
					{
						x2 = wolf->player->x - (1 - wolf->player->y + (int)(wolf->player->y)) / tan(angle);
						x_step = y_step / tan(angle);
					}
					else
					{
						x2 = 1 + (int)wolf->player->x;
						x_step = 0;
					}
				}
				while (x2 >= 0 && x2 < wolf->width && y2>= 0 && y2< (wolf->heigth))
				{
					if (*(wolf->map + (int)(x2) + ((int)y2 - 1) * wolf->width) != '0')
						break ;
					if (*(wolf->map + (int)(x2) + ((int)y2) * wolf->width) != '0')
						break ;
					y2 = y2 - y_step;
					x2 = x2 + x_step;
				}
			}
			else
			{
				y2 = -1;
				x2 = -1;
			}
			p = 0;
			if ((x2 >= 0 && x2 < wolf->width && y2 >= 0 && y2 < (wolf->heigth)) && !(x1 >= 0 && x1 < wolf->width && y1 >= 0 && y1 < (wolf->heigth)))
			{
				p = (x2 - wolf->player->x) * cos(wolf->player->angle) + (wolf->player->y - y2) * sin(wolf->player->angle);
				color_wall = 0x008800;
				pos = x2 - (int)x2;
			}
			else if (x1 >= 0 && x1 < wolf->width && y1 >= 0 && y1 < (wolf->heigth) && !(x2 >= 0 && x2 < wolf->width && y2 >= 0 && y2 < (wolf->heigth)))
			{
				color_wall = 0xBB0000;
				p = (x1 - wolf->player->x) * cos(wolf->player->angle) + (wolf->player->y - y1) * sin(wolf->player->angle);
				pos = y1 - (int)y1;
			}
			else if (x1 >= 0 && x1 < wolf->width && y1 >= 0 && y1 < (wolf->heigth) && x2 >= 0 && x2 < wolf->width && y2 >= 0 && y2 < (wolf->heigth))
			{
				color_wall = 0x008800;
				if (fabs(x1 - wolf->player->x) < fabs(wolf->player->x - x2))
				{
					x2 = x1;
					y2 = y1;
					color_wall = 0xBB0000;
					pos = y2 - (int)y2;
				}
				else
					pos = x2 - (int)x2;
				p = (x2 -  wolf->player->x) * cos(wolf->player->angle) + (wolf->player->y - y2) * sin(wolf->player->angle);
			}
			if (p != 0)
				p = fabs(900 / p);
			y1 = 0;
			if (color_wall == 0x008800)
				pos = (int)(pos * (wolf->tx + 1)->width);
			else
				pos = (int)(pos * (wolf->tx)->width);
			while (y1 < wolf->win_heidth)
			{
				if (y1 < wolf->line_horizon - p / 2)
					color = 0xFFFFFF;	
				else if (y1 < wolf->line_horizon + p / 2)
				{
					if (color_wall == 0x008800)
					{
						color = ((int*)(wolf->tx + 1)->start_img)[(int)pos + (int)((y1 - wolf->line_horizon + p / 2) / p * (wolf->tx + 1)->heidth) * (wolf->tx + 1)->width];
					}
					else
					{
						color = ((int*)wolf->tx->start_img)[(int)pos + (int)((y1 - wolf->line_horizon + p / 2) / p * wolf->tx->heidth) * wolf->tx->width];
					}
				}
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
}
