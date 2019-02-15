/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfalmer- <bfalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 17:37:27 by thorker           #+#    #+#             */
/*   Updated: 2019/02/15 15:59:49 by bfalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int		main()
{
	//
	t_wolf	*wolf;
	wolf = create_struct();
	wolf->ft_opencl = init_opencl("wolf3d.cl", "wolf");
	put_img(wolf);
	hook(wolf);
	mlx_loop(wolf->mlx_ptr);
	(void)wolf;
}
