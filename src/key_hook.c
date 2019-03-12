/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfalmer- <bfalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 19:00:12 by bfalmer-          #+#    #+#             */
/*   Updated: 2019/03/12 16:49:37 by bfalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		player_move(int key, t_wolf *wolf, char k)
{
	if (key == 13)
		wolf->move_forward = k;
	if (key == 1)
		wolf->move_back = k;
	if (key == 0)
		wolf->move_left = k;
	if (key == 2)
		wolf->move_right = k;
	else if (key == 12)
		wolf->turn_left = k;
	else if (key == 14)
		wolf->turn_right = k;
	return (0);
}

int		key_menu(int key, t_wolf *wolf)
{
	if (wolf->menu_string == 1 && key == 49)
	{
		if (wolf->fov[0] == 3)
			wolf->fov[0] = 1;
		else
			wolf->fov[0]++;
	}
	if (wolf->menu_string == 2 && key == 49)
	{
		if (wolf->mouse_speed[0] == 3)
			wolf->mouse_speed[0] = 1;
		else
			wolf->mouse_speed[0]++;
	}
	if (key == 126 && (wolf->menu_string > 1))
		wolf->menu_string -= 1;
	if (key == 125 && (wolf->menu_string < 4))
		wolf->menu_string += 1;
	return (0);
}

int		key_press(int key, t_wolf *wolf)
{
	if (key == 53)
	{
		system("killall afplay");
		exit(1);
	}
	if (key == 13 || key == 1 || key == 0 || key == 2 || key == 12 || key == 14)
		player_move(key, wolf, 1);
	if (key == 48 && wolf->menu == 1)
		wolf->menu = 0;
	else if (key == 48 && wolf->menu == 0)
		wolf->menu = 1;
	if ((key == 49 || key == 125 || key == 126) && wolf->menu == 1)
		key_menu(key, wolf);
	if (key == 257)
		wolf->step = 0.06;
	mlx_clear_window(wolf->mlx_ptr, wolf->win_ptr);
	put_img(wolf);
	return (0);
}

int		key_release(int key, t_wolf *wolf)
{
	if (key == 13 || key == 1 || key == 0 || key == 2 || key == 12 || key == 14)
		player_move(key, wolf, 0);
	if (key == 257)
		wolf->step = 0.03;
	mlx_clear_window(wolf->mlx_ptr, wolf->win_ptr);
	put_img(wolf);
	return (0);
}
