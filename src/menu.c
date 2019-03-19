/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfalmer- <bfalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 15:48:36 by bfalmer-          #+#    #+#             */
/*   Updated: 2019/03/19 19:48:36 by bfalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	move_menu_string(t_wolf *wolf)
{
	int	part;
	int	y;
	int	x;

	part = wolf->win_heidth / 8 * (wolf->menu_string + 1);
	y = 0;
	while (y < (wolf->win_heidth / 8))
	{
		x = 0;
		while (x < wolf->win_width / 3)
		{
			((int*)wolf->start_img)[(int)(((y + part) * wolf->win_width) +
				(x + wolf->win_width / 20))] = 0xff0000;
			x++;
		}
		y++;
	}
}

static void	draw_square(t_wolf *wolf, double part)
{
	int y;
	int x;
	int color;
	int new_x;
	int	new_y;

	y = -1;
	while (++y < (wolf->win_heidth / part))
	{
		new_y = (wolf->tx + 5)->heidth / (wolf->win_heidth / part / y);
		x = -1;
		while (++x < (wolf->win_width))
		{
			new_x = (wolf->tx + 5)->width / (wolf->win_width / part / x);
			color = ((int*)(wolf->tx + 5)->start_img)[(int)(new_y *
				(wolf->tx + 5)->width + new_x)];
			((int*)wolf->start_img)[(int)((y * wolf->win_width) + x)] = color;
		}
	}
}

static void	put_string(t_wolf *wolf, int x, int y, char *text)
{
	mlx_string_put(wolf->mlx_ptr, wolf->win_ptr, x, y, 0xFFFFFF, text);
}

int			add_text(t_wolf *wolf)
{
	char	*buff;

	if (wolf->menu == 1)
	{
		put_string(wolf, wolf->win_width / 12, wolf->win_heidth / 100 * 20,
			"Settings:");
		put_string(wolf, wolf->win_width / 12, wolf->win_heidth / 100 * 30,
			"FOV");
		put_string(wolf, wolf->win_width / 12 * 2, wolf->win_heidth / 100 * 30,
			buff = ft_itoa(wolf->fov[(int)(wolf->fov[0])] / 3.14 * 180));
		free(buff);
		put_string(wolf, wolf->win_width / 12, wolf->win_heidth / 100 * 42,
			"Mouse speed");
		put_string(wolf, wolf->win_width / 12 * 2, wolf->win_heidth / 100 * 42,
			buff = ft_itoa(wolf->mouse_speed[wolf->mouse_speed[0]]));
		free(buff);
		put_string(wolf, wolf->win_width / 12, wolf->win_heidth / 100 * 55,
			"- - -");
		put_string(wolf, wolf->win_width / 12, wolf->win_heidth / 100 * 68,
			"- - -");
		put_string(wolf, wolf->win_width / 12, wolf->win_heidth / 100 * 78,
			"(c.)");
	}
	return (0);
}

void		menu(t_wolf *wolf)
{
	draw_square(wolf, 1);
	move_menu_string(wolf);
}
