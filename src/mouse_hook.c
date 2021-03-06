/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfalmer- <bfalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 15:57:06 by thorker           #+#    #+#             */
/*   Updated: 2019/03/12 16:13:02 by bfalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int	mouse_move(int x, int y, t_wolf *wolf)
{
	if (wolf->mouse_x == -1)
		wolf->mouse_x = x;
	else
	{
		if (wolf->mouse_x >= x)
			wolf->player->angle += ANGLE * (wolf->mouse_x - x) /
				wolf->mouse_speed[wolf->mouse_speed[0]];
		if (wolf->mouse_x <= x || x == 0)
			wolf->player->angle -= ANGLE * (x - wolf->mouse_x) /
				wolf->mouse_speed[wolf->mouse_speed[0]];
		wolf->mouse_x = x;
	}
	(void)y;
	return (0);
}
