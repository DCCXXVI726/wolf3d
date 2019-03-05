/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfalmer- <bfalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 18:44:08 by bfalmer-          #+#    #+#             */
/*   Updated: 2019/03/05 14:13:30 by thorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int     ft_close(t_wolf *wolf)
{
    (void)wolf;
    system("killall afplay");
    exit(1);
    return 0;
}

void    hook(t_wolf *wolf)
{
    //mlx_hook(wolf->win_ptr, 2, 0, key_press, wolf);
	mlx_hook(wolf->win_ptr, 17, 0, ft_close, wolf);
    mlx_hook(wolf->win_ptr, 6, 0, mouse_move, wolf);
	//mlx_hook(wolf->win_ptr, 3, 0, key_release, wolf);
}
