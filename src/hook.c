/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfalmer- <bfalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 18:44:08 by bfalmer-          #+#    #+#             */
<<<<<<< HEAD:src/hook.c
/*   Updated: 2019/02/15 15:26:46 by bfalmer-         ###   ########.fr       */
=======
/*   Updated: 2019/02/15 15:33:59 by thorker          ###   ########.fr       */
>>>>>>> 0acf0185e3b48561a75ff374d77dfcd36980292e:hook.c
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int     ft_close(t_wolf *wolf)
{
    (void)wolf;
    exit(1);
    return 0;
}

void    hook(t_wolf *wolf)
{
    mlx_hook(wolf->win_ptr, 2, 0, key_press, wolf);
	mlx_hook(wolf->win_ptr, 17, 0, ft_close, wolf);
}
