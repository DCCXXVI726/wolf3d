/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thorker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 15:57:06 by thorker           #+#    #+#             */
/*   Updated: 2019/03/09 15:57:09 by thorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int     mouse_move(int x, int y, t_wolf *wolf)
{
    
    if (wolf->mouse_x >= x)
        wolf->player->angle += ANGLE;
    if (wolf->mouse_x <= x || x == 0)
        wolf->player->angle -= ANGLE;
    wolf->mouse_x = x;
    (void)y;
    return (0);
}
