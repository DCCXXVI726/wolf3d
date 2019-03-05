/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfalmer- <bfalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 17:37:27 by thorker           #+#    #+#             */
/*   Updated: 2019/03/05 20:10:40 by thorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		main()
{
	int h;
	int w;
	t_wolf	*wolf;
	void	*img_ptr2;
	wolf = create_struct();
	hook(wolf);
	//system("afplay src/doom.mp3 -v 0.3 &");
	h = 600;
	w = 600;
	img_ptr2 = mlx_xpm_file_to_image(wolf->mlx_ptr, "cat.xpm", &w, &h);
	ft_putnbrln(w);
	ft_putnbrln(h);
	mlx_put_image_to_window(wolf->mlx_ptr, wolf->win_ptr, img_ptr2, 0, 0);
	//mlx_loop_hook(wolf->mlx_ptr, put_img, wolf);
	mlx_loop(wolf->mlx_ptr);
}
