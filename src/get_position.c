/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_position.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfalmer- <bfalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 19:53:18 by bfalmer-          #+#    #+#             */
/*   Updated: 2019/03/11 20:10:07 by bfalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	sup_get_p2(t_wolf *wolf, t_orientation *orientation)
{
	if (sin(orientation->angle) > 0)
	{
		orientation->y = (int)wolf->player->y;
		orientation->y_step = 1;
		orientation->x = wolf->player->x + (wolf->player->y -
			(int)(wolf->player->y)) / tan(orientation->angle);
	}
	else
	{
		orientation->y = 1 + (int)wolf->player->y;
		orientation->y_step = -1;
		orientation->x = wolf->player->x - (1 - wolf->player->y +
			(int)(wolf->player->y)) / tan(orientation->angle);
	}
}

static int	get_p2(t_wolf *wolf, t_orientation *orientation, double *p,
					double *pos)
{
	double	p1;
	double	pos1;

	orientation->orientation = 0;
	sup_get_p2(wolf, orientation);
	orientation->x_step = orientation->y_step / tan(orientation->angle);
	find_orientation_p2(orientation, wolf);
	p1 = 0;
	if (orientation->orientation != 0)
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

static void	sup_get_p(t_wolf *wolf, t_orientation *orientation)
{
	if (cos(orientation->angle) > 0)
	{
		orientation->x = 1 + (int)(wolf->player->x);
		orientation->x_step = 1;
		orientation->y = wolf->player->y - (1 + (int)(wolf->player->x) -
			wolf->player->x) * tan(orientation->angle);
	}
	else
	{
		orientation->x = (int)wolf->player->x;
		orientation->x_step = -1;
		orientation->y = wolf->player->y + (wolf->player->x -
			(int)(wolf->player->x)) * tan(orientation->angle);
	}
}

void		get_p(t_wolf *wolf, t_main_window *window)
{
	t_orientation *orientation;

	orientation = (t_orientation*)malloc(sizeof(t_orientation));
	orientation->angle = wolf->player->angle + wolf->fov[(int)(wolf->fov[0])] *
		(1.0 / 2 - ((double)(window->i)) / wolf->iteration);
	sup_get_p(wolf, orientation);
	orientation->y_step = orientation->x_step * tan(orientation->angle);
	find_orientation_p(orientation, wolf);
	window->p = 0;
	if (wolf->orientation != 0)
	{
		window->p = (orientation->x - wolf->player->x) *
			cos(wolf->player->angle) + (wolf->player->y -
				orientation->y) * sin(wolf->player->angle);
		window->pos = orientation->y - (int)orientation->y;
	}
	if (get_p2(wolf, orientation, &window->p, &window->pos) == 1)
		wolf->orientation = (int)orientation->angle;
}
