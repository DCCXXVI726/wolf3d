/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thorker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 17:39:10 by thorker           #+#    #+#             */
/*   Updated: 2019/02/10 18:59:14 by thorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	init_mlx(t_wolf *new)
{
	new->mlx_ptr = mlx_init();
	new->win_ptr = mlx_new_window(new->mlx_ptr, 1000, 1000,
			"Wolf3d");
	new->img1_ptr = mlx_new_image(new->mlx_ptr, 1000, 1000);
	new->start_img1 = mlx_get_data_addr(new->img1_ptr, &(new->bpp),
			&(new->size_line), &(new->endian));
	new->img2_ptr = mlx_new_image(new->mlx_ptr, 1000, 1000);
	new->start_img2 = mlx_get_data_addr(new->img2_ptr, &(new->bpp),
			&(new->size_line), &(new->endian));
	new->img3_ptr = mlx_new_image(new->mlx_ptr, 1000, 1000);
	new->start_img3 = mlx_get_data_addr(new->img3_ptr, &(new->bpp),
			&(new->size_line), &(new->endian));
}

t_wolf	*create_struct()
{
	t_wolf  *new;

	if ((new = (t_wolf*)malloc(sizeof(t_wolf))) == 0)
		check_error_n_exit(1, "Didn't create wold sctruct");
	init_mlx(new);
	new->limit = 1000 * 1000;
	return(new);
}
