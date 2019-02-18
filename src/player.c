/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfalmer- <bfalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 13:07:41 by bfalmer-          #+#    #+#             */
/*   Updated: 2019/02/18 15:35:35 by thorker          ###   ########.fr       */
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
	ft_putnbrln((int)wolf->player->x);
	ft_putnbrln((int)wolf->player->y);
	ft_putnbrln((int)(wolf->player->angle * 1000));
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
	y -= 10;
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
