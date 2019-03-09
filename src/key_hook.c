/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfalmer- <bfalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 19:00:12 by bfalmer-          #+#    #+#             */
/*   Updated: 2019/03/05 15:11:02 by thorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int     player_move(int key, t_wolf *wolf, char k)
{
    if (key == 13)
	{
		if (k == 1)
			wolf->move_forward = 1;
		else 
			wolf->move_forward = 0;
	}
    if (key == 1)
    {
		if (k == 1)
			wolf->move_back = 1;
		else
			wolf->move_back = 0;
	}
    if (key == 0)
    {
		if (k == 1)
			wolf->move_left = 1;
		else
			wolf->move_left = 0;
	}
    if (key == 2)
    {
		if (k == 1)
			wolf->move_right = 1;
		else
			wolf->move_right = 0;
	}
    return 0;

}

int     key_press(int key, t_wolf *wolf)
{
    if (key == 53)
    {
        system("killall afplay");
        exit(1);
    }
    if (key == 13 || key == 1 || key == 0 || key == 2)
        player_move(key, wolf, 1);
	if (key == 257)
		wolf->step = 0.03;
	if (key == 256)
		system("killall afplay sounds/main.mp3");
    mlx_clear_window(wolf->mlx_ptr, wolf->win_ptr);
    put_img(wolf);
    return 0;
    
}

int		key_release(int key, t_wolf *wolf)
{
	if (key == 13 || key == 1 || key == 0 || key == 2)
		player_move(key, wolf, 0);
	if (key == 257)
		wolf->step = 0.01;
	mlx_clear_window(wolf->mlx_ptr, wolf->win_ptr);
	put_img(wolf);
	return 0;
}
