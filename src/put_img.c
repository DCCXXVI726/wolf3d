/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfalmer- <bfalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 13:58:41 by thorker           #+#    #+#             */
/*   Updated: 2019/03/12 15:02:49 by thorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static int	put_fps(t_wolf *wolf)
{
	gettimeofday(&wolf->time, NULL);
	if (wolf->time.tv_sec > wolf->old_time.tv_sec)
		mlx_string_put(wolf->mlx_ptr,
			wolf->win_ptr, 0, 0, 0xFF0000, ft_itoa(((int)(TIME /
				(wolf->time.tv_usec + TIME - wolf->old_time.tv_usec)))));
	else
		mlx_string_put(wolf->mlx_ptr, wolf->win_ptr, 0, 0,
			0xFF0000, ft_itoa((int)(TIME / (wolf->time.tv_usec -
				wolf->old_time.tv_usec))));
	return (1);
}

static void	draw_hands(t_wolf *wolf)
{
	double	x;
	double	y;
	int		new_x;
	int		new_y;
	int		color;

	y = -1;
	while (++y < wolf->win_heidth / 2)
	{
		new_y = y / (wolf->win_heidth / 2) * (wolf->tx + 2)->heidth;
		x = -1;
		while (++x < wolf->win_width / 3)
		{
			new_x = x / (wolf->win_width / 3) * (wolf->tx + 2)->width;
			if (((int*)(wolf->tx + 2)->start_img)[new_y *
				(wolf->tx + 2)->width + new_x] != 0xFFFFFF)
			{
				color = ((int*)(wolf->tx + 2)->start_img)[new_y *
					(wolf->tx + 2)->width + new_x];
				((int*)wolf->start_img)[(int)(((y + wolf->win_heidth / 2) *
					wolf->win_width) +
						(x + wolf->win_width / 100 * 45))] = color;
			}
		}
	}
}

static void	main_window(t_wolf *wolf, t_main_window *window)
{
	while (++(window->i) < wolf->iteration)
	{
		wolf->orientation = 0;
		get_p(wolf, window);
		if (window->p != 0)
			window->p = fabs(1500 / window->p);
		window->y = -1;
		define_wall(wolf);
		window->pos = (int)(window->pos * (wolf->curr_tx)->width);
		while (++(window->y) < wolf->win_heidth)
		{
			define_color(wolf, window);
			window->x = (double)window->i * wolf->win_width / wolf->iteration;
			while (window->x < (window->i + 1) *
				(double)wolf->win_width / wolf->iteration &&
					window->x < wolf->win_width)
			{
				((int*)wolf->start_img)[(int)(window->y *
					wolf->win_width + window->x)] = window->color;
				window->x++;
			}
		}
	}
	draw_hands(wolf);
}

int			put_img(t_wolf *wolf)
{
	t_main_window *window;

	if ((window = (t_main_window*)malloc(sizeof(t_main_window))) == 0)
		check_error_n_exit(1, "Didn't create window sctruct");
	window->i = -1;
	if (wolf->menu == 0)
	{
		moving(wolf);
		main_window(wolf, window);
	}
	else
		menu(wolf);
	wolf->old_time = wolf->time;
	mlx_put_image_to_window(wolf->mlx_ptr, wolf->win_ptr, wolf->img_ptr, 0, 0);
	add_text(wolf);
	put_fps(wolf);
	free(window);
	return (0);
}
