/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thorker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 13:58:41 by thorker           #+#    #+#             */
/*   Updated: 2019/03/05 16:36:27 by thorker          ###   ########.fr       */
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
	double x;
	double y;

	
	if (wolf->move_forward == 1)
	{
		x = wolf->player->x + STEP * cos(wolf->player->angle);
		y = wolf->player->y - STEP * sin(wolf->player->angle);
		if (wolf->map[(int)(y) * wolf->width + (int)(x)] == '0')
		{
			wolf->player->x = x;
			wolf->player->y = y;
		}
	}
	if (wolf->move_back	== 1)
	{
		x = wolf->player->x - STEP * cos(wolf->player->angle);
		y = wolf->player->y + STEP * sin(wolf->player->angle);
		if (wolf->map[(int)(y) * wolf->width + (int)(x)] == '0')
		{
			wolf->player->x = x;
			wolf->player->y = y;
		}
	}
	if (wolf->move_right == 1)
	{
		x = wolf->player->x - STEP * cos(wolf->player->angle + 3.14 / 2);
		y = wolf->player->y + STEP * sin(wolf->player->angle + 3.14 / 2);
		if (wolf->map[(int)(y) * wolf->width + (int)(x)] == '0')
		{
			wolf->player->x = x;
			wolf->player->y = y;
		}
	}
	if (wolf->move_left == 1)
	{
		x = wolf->player->x - STEP * cos(wolf->player->angle - 3.14 / 2);
		y = wolf->player->y + STEP * sin(wolf->player->angle - 3.14 / 2);
		if (wolf->map[(int)(y) * wolf->width + (int)(x)] == '0')
		{
			wolf->player->x = x;
			wolf->player->y = y;
		}
	}
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
        }
        if (x1 >= 0 && x1 < wolf->width && y1 >= 0 && y1 < (wolf->heigth) && !(x2 >= 0 && x2 < wolf->width && y2 >= 0 && y2 < (wolf->heigth)))
        {
            p = (x1 - wolf->player->x) * cos(wolf->player->angle) + (wolf->player->y - y1) * sin(wolf->player->angle);
        }
        if (x1 >= 0 && x1 < wolf->width && y1 >= 0 && y1 < (wolf->heigth) && x2 >= 0 && x2 < wolf->width && y2 >= 0 && y2 < (wolf->heigth))
        {
            if (fabs(x1 - wolf->player->x) < fabs(wolf->player->x - x2))
            {
                x2 = x1;
                y2 = y1;
            }
            p = (x2 -  wolf->player->x) * cos(wolf->player->angle) + (wolf->player->y - y2) * sin(wolf->player->angle);
        }
        if (p != 0 && fabs(500/p) < 1000)
        {
            p = fabs(500 / p);
		}
		else
			p = 1000;
		y1 = 0;
		while (y1 < 1000)
		{
			if (y1 < 500 - p / 2)
				color = 0xFFFFFF;	
			else if (y1 < 500 + p / 2)
				color = 0x008800;
			else
				color = 0;
			x1 = i * 1000 / wolf->iteration;
			while (x1 < (i + 1) * 1000 / wolf->iteration)
			{
				((int*)wolf->start_img1)[((int)y1) * 1000 + ((int)x1)] = color;
				x1++;
			}
			y1++;
		}
		i++;
	}
	mlx_put_image_to_window(wolf->mlx_ptr, wolf->win_ptr, wolf->img1_ptr, 0, 0);
	return (0);
}
