/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfalmer- <bfalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 17:37:27 by thorker           #+#    #+#             */
/*   Updated: 2019/03/14 15:50:44 by thorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static char	*check_parametrs(int ac, char *av[])
{
	char *map_name;

	if (ac != 2)
		check_error_n_exit(1, "Usage ./wolf3d FILE_MAP");
	if (ac == 1)
		map_name = ft_strdup("map");
	else
		map_name = av[0];
	return (map_name);
}

int			main(int ac, char *av[])
{
	t_wolf	*wolf;
	char	*map_name;

	map_name = check_parametrs(ac, &av[1]);
	wolf = create_struct(map_name);
	hook(wolf);
	system("afplay sounds/doom.mp3 -v 0.3 &");
	mlx_loop_hook(wolf->mlx_ptr, put_img, wolf);
	mlx_loop(wolf->mlx_ptr);
}
