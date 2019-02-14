/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfalmer- <bfalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 19:00:12 by bfalmer-          #+#    #+#             */
/*   Updated: 2019/02/14 19:56:11 by bfalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int     player_move(int key, t_wolf *wolf)
{
    if (key == 13)
    {
        wolf->player->x -= 10 * cos(wolf->player->angle);
        wolf->player->y -= 10 * sin(wolf->player->angle);
    }
    if (key == 1)
    {
        wolf->player->x += 5 * cos(wolf->player->angle);
        wolf->player->y += 5 * sin(wolf->player->angle);
    }
    if (key == 0)
        wolf->player->angle -= 5;
    if (key == 2)
        wolf->player->angle += 5;
    return 0;

}

int     key_press(int key, t_wolf *wolf)
{
    (void)wolf;
    if (key == 53)
        exit(1);
    if (key == 13 || key == 1 || key == 0 || key == 2)
        player_move(key, wolf);
    mlx_clear_window(wolf->mlx_ptr, wolf->win_ptr);
    put_img(wolf);
    return 0;
    
}
