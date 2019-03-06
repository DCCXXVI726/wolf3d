/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfalmer- <bfalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 17:37:27 by thorker           #+#    #+#             */
/*   Updated: 2019/03/06 17:06:38 by thorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		main()
{
	t_wolf	*wolf;

	wolf = create_struct();
	hook(wolf);
	//system("afplay src/doom.mp3 -v 0.3 &");
	wolf->img_ptr_tx = mlx_xpm_file_to_image(wolf->mlx_ptr, "WALL0.xpm", &wolf->width_tx, &wolf->heigth_tx);
	wolf->start_img_tx = mlx_get_data_addr(wolf->img_ptr_tx, &wolf->bpp_tx, &wolf->size_line_tx, &wolf->endian_tx);
	wolf->img_ptr_tx2 = mlx_xpm_file_to_image(wolf->mlx_ptr, "cat.xpm", &wolf->width_tx2, &wolf->heigth_tx2);
	wolf->start_img_tx2 = mlx_get_data_addr(wolf->img_ptr_tx2, &wolf->bpp_tx2, &wolf->size_line_tx2, &wolf->endian_tx2);
	mlx_put_image_to_window(wolf->mlx_ptr, wolf->win_ptr, wolf->img_ptr_tx, 0, 0);
	mlx_loop_hook(wolf->mlx_ptr, put_img, wolf);
	mlx_loop(wolf->mlx_ptr);
}
