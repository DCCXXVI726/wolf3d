/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thorker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 17:37:27 by thorker           #+#    #+#             */
/*   Updated: 2019/02/10 19:15:02 by thorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		main()
{
	t_wolf	*wolf;
	wolf = create_struct();
	wolf->ft_opencl = init_opencl("wolf3d.cl", "wolf");
	put_img(wolf);
	mlx_loop(wolf->mlx_ptr);
}
