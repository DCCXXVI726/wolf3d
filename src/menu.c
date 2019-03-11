/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfalmer- <bfalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 15:48:36 by bfalmer-          #+#    #+#             */
/*   Updated: 2019/03/11 15:48:39 by bfalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	move_menu_string(t_wolf *wolf)
{
	int part;
	int y;
	int x;

	part = wolf->win_heidth / 8 * (wolf->menu_string + 1);
	y = 0;
	while (y < (wolf->win_heidth / 8))
	{
		x = 0;
		while (x < wolf->win_width / 3)
		{
			((int*)wolf->start_img)[(int)(((y + part) * wolf->win_width) + (x + wolf->win_width / 20))] = 0xff0000;
			x++;
		}
		y++;
	}
}

void	draw_square(t_wolf *wolf, double part)
{
	int y;
	int x;
	int color;

	y = -1;
	while (++y < (wolf->win_heidth / part))
	{
		int new_y = (wolf->tx + 5)->heidth / (wolf->win_heidth / part / y);
		x = -1;
		while (++x < (wolf->win_width))
		{
			
			int new_x = (wolf->tx + 5)->width / (wolf->win_width / part / x);
			//if ((y > wolf->win_heidth / 6 && y < wolf->win_heidth / 100 * 85) && (x < wolf->win_width / 100 * 50))
			//	color = ((int*)(wolf->tx + 5)->start_img)[(int)(new_y * (wolf->tx + 5)->width + new_x)] + 90;
			//else
				color = ((int*)(wolf->tx + 5)->start_img)[(int)(new_y * (wolf->tx + 5)->width + new_x)];
			((int*)wolf->start_img)[(int)((y * wolf->win_width) + x)] = color;
		}
	}
}

int		add_text(t_wolf *wolf)
{
	if (wolf->menu == 1)
	{
		mlx_string_put(wolf->mlx_ptr, wolf->win_ptr, wolf->win_width / 12 , wolf->win_heidth / 100 * 20,
			0xFFFFFF, "Menu:");
		mlx_string_put(wolf->mlx_ptr, wolf->win_ptr, wolf->win_width / 12, wolf->win_heidth / 100 * 30,
			0xFFFFFF, "FOV:");
		mlx_string_put(wolf->mlx_ptr, wolf->win_ptr, wolf->win_width / 12 * 2, wolf->win_heidth / 100 * 30,
			0xFFFFFF, ft_itoa(wolf->fov[(int)(wolf->fov[0])] / 3.14 * 180));
		mlx_string_put(wolf->mlx_ptr, wolf->win_ptr, wolf->win_width / 12, wolf->win_heidth / 100 * 42,
			0xFFFFFF, "Mouse speed:");
		mlx_string_put(wolf->mlx_ptr, wolf->win_ptr, wolf->win_width / 12 * 2, wolf->win_heidth / 100 * 42,
			0xFFFFFF, ft_itoa(wolf->mouse_speed[wolf->mouse_speed[0]]));
		mlx_string_put(wolf->mlx_ptr, wolf->win_ptr, wolf->win_width / 12, wolf->win_heidth / 100 * 55,
			0xFFFFFF, "SRAKA:");
		mlx_string_put(wolf->mlx_ptr, wolf->win_ptr, wolf->win_width / 12, wolf->win_heidth / 100 * 68,
			0xFFFFFF, "SRAKA:");
		mlx_string_put(wolf->mlx_ptr, wolf->win_ptr, wolf->win_width / 12, wolf->win_heidth / 100 * 78,
			0xFFFFFF, "made by SRAKA 2019");
	}
	return (0);
}

void	menu(t_wolf *wolf)
{
	draw_square(wolf, 1);
	move_menu_string(wolf);
}
