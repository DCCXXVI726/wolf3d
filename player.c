/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfalmer- <bfalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 13:07:41 by bfalmer-          #+#    #+#             */
/*   Updated: 2019/02/15 14:21:21 by bfalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		put_player(t_wolf *wolf)
{
	int x;
	int y;
	int i;
	int k;

	x = 500;
	y = 500;
	k = -5;
	ft_putnbrln(x);
	ft_putnbrln(y);
	while (k < 5)
	{
		i = -5;
		while (i < 5)
		{
			if ((i + x >= 0) && (i + x < 1000) && (k + y >= 0) && (k + y < 1000))
				((int*)wolf->start_img1)[(y + k)  * 1000 + x + i] = 0xFF0000;
			i++;
		}
		k++;
	}
	x += 10 * cos(wolf->player->angle);
	y += 10 * sin(wolf->player->angle);
	k = -3;
	while (k < 3)
	{
		i = -3;
		while (i < 3)
		{
			if ((i + x >= 0) && (i + x < 1000) && (k + y >= 0) && (k + y < 1000))
				((int*)wolf->start_img1)[(y + k)  * 1000 + x + i] = 0xFFFF00;
			i++;
		}
		k++;
    }
}