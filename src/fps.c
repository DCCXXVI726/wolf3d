/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fps.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfalmer- <bfalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 16:47:11 by bfalmer-          #+#    #+#             */
/*   Updated: 2019/03/11 16:48:28 by bfalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int put_fps(t_wolf *wolf)
{
	gettimeofday(&wolf->time, NULL);
	if (wolf->time.tv_sec > wolf->old_time.tv_sec)
		mlx_string_put(wolf->mlx_ptr,
			wolf->win_ptr, 0, 0, 0xFF0000, ft_itoa(((int)(TIME /
				(wolf->time.tv_usec + TIME - wolf->old_time.tv_usec)))));
	else
		mlx_string_put(wolf->mlx_ptr, wolf->win_ptr, 0, 0, 0xFF0000,
			ft_itoa((int)(TIME / (wolf->time.tv_usec -
				wolf->old_time.tv_usec))));
				return (1);
	wolf->old_time = wolf->time;
	gettimeofday(&wolf->time, NULL);
	if (wolf->time.tv_sec > wolf->old_time.tv_sec)
		mlx_string_put(wolf->mlx_ptr, wolf->win_ptr, 0, 0, 0xFF0000,
				ft_itoa(((int)(TIME / (wolf->time.tv_usec + TIME -
								wolf->old_time.tv_usec)))));
	else
		mlx_string_put(wolf->mlx_ptr, wolf->win_ptr, 0, 0, 0xFF0000,
				ft_itoa(((int)(TIME / (wolf->time.tv_usec -
								wolf->old_time.tv_usec)))));
	return (1);
}
