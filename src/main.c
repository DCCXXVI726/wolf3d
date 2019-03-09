/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfalmer- <bfalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 17:37:27 by thorker           #+#    #+#             */
/*   Updated: 2019/03/09 14:42:32 by thorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int	main(void)
{
	t_wolf	*wolf;

	wolf = create_struct();
	hook(wolf);
	system("afplay sounds/doom.mp3 -v 0.3 &");
	mlx_loop_hook(wolf->mlx_ptr, put_img, wolf);
	mlx_loop(wolf->mlx_ptr);
}
