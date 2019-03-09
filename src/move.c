/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thorker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 15:33:14 by thorker           #+#    #+#             */
/*   Updated: 2019/03/09 16:14:15 by thorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	step2(t_wolf *wolf)
{
	if (wolf->step_ill > 3.14 / 2)
	{
		wolf->step_ill += 3.14 / 60;
		if (wolf->step_ill >= 3.14)
			wolf->step_ill = 0;
	}
	else if (wolf->step_ill >= 3.14 / 60)
		wolf->step_ill -= 3.14 / 60;
	else if (wolf->step_ill == 3.14 / 120)
		wolf->step_ill = 0;
}

static void	step(t_wolf *wolf)
{
	if (wolf->move_back == 1 || wolf->move_forward == 1
			|| wolf->move_left == 1 || wolf->move_right == 1)
	{
		if (wolf->step > 0.01)
			wolf->step_count += 2;
		else
			wolf->step_count += 1;
		if (wolf->step_count > 30)
			system("afplay sounds/step.wav &");
		if (wolf->step_count > 30)
			wolf->step_count = 0;
		if (wolf->step_ill == 0 || wolf->step == 3.14 / 120)
			wolf->step_ill += 3.14 / 120;
		else if (wolf->step_ill < 3.14)
			wolf->step_ill += 3.14 / 60;
		else
			wolf->step_ill = 3.14 / 60;
	}
	else
		step2(wolf);
	wolf->line_horizon = wolf->win_heidth / 2 +
		wolf->win_heidth / 20 * sin(wolf->step_ill);
}

static void	moving_left_right(t_wolf *wolf, double x_change, double y_change)
{
	if (wolf->move_right == 1)
		if (wolf->map[(int)(wolf->player->y + x_change) * wolf->width
				+ (int)(wolf->player->x + y_change)] == '0')
		{
			wolf->player->x += y_change;
			wolf->player->y += x_change;
		}
	if (wolf->move_left == 1)
		if (wolf->map[(int)(wolf->player->y - x_change) * wolf->width
				+ (int)(wolf->player->x - y_change)] == '0')
		{
			wolf->player->x -= y_change;
			wolf->player->y -= x_change;
		}
}

void		moving(t_wolf *wolf)
{
	double x_change;
	double y_change;

	step(wolf);
	x_change = wolf->step * cos(wolf->player->angle);
	y_change = wolf->step * sin(wolf->player->angle);
	if (wolf->move_forward == 1)
		if (wolf->map[(int)(wolf->player->y - y_change) * wolf->width
				+ (int)(wolf->player->x + x_change)] == '0')
		{
			wolf->player->x += x_change;
			wolf->player->y -= y_change;
		}
	if (wolf->move_back == 1)
		if (wolf->map[(int)(wolf->player->y + y_change) * wolf->width
				+ (int)(wolf->player->x - x_change)] == '0')
		{
			wolf->player->x -= x_change;
			wolf->player->y += y_change;
		}
	moving_left_right(wolf, x_change, y_change);
}
