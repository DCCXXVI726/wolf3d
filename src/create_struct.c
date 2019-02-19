/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfalmer- <bfalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 17:39:10 by thorker           #+#    #+#             */
/*   Updated: 2019/02/18 15:50:22 by thorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	read_map(t_wolf *new, char *name)
{
	char	*tmp;
	char	*old_tmp;
	char	*line;
	int		gnl;
	int		fd;

	tmp = ft_strnew(0);
	if ((fd = open(name, O_RDONLY)) < 0)
		check_error_n_exit(1, "Didn't open file map");
	while ((gnl = get_next_line(fd, &line)) != 0)
	{
		if (gnl == -1)
			check_error_n_exit(1, "Didn't read file");
		new->width = ft_strlen(line);
		old_tmp = tmp;
		tmp = ft_strjoin(tmp, line);
		free(old_tmp);
		free(line);
	}
	new->heigth = ft_strlen(tmp) / new->width;
	if (ft_strlen(tmp) == 0)
		ft_strdel(&tmp);
	close(fd);
	new->map = tmp;
}

static void	init_mlx(t_wolf *new)
{
	new->mlx_ptr = mlx_init();
	new->win_ptr = mlx_new_window(new->mlx_ptr, 1000, 1000,
			"Wolf3d");
	new->img1_ptr = mlx_new_image(new->mlx_ptr, 1000, 1000);
	new->start_img1 = mlx_get_data_addr(new->img1_ptr, &(new->bpp),
			&(new->size_line), &(new->endian));
	/*new->img2_ptr = mlx_new_image(new->mlx_ptr, 1000, 1000);
	new->start_img2 = mlx_get_data_addr(new->img2_ptr, &(new->bpp),
			&(new->size_line), &(new->endian));
	new->img3_ptr = mlx_new_image(new->mlx_ptr, 1000, 1000);
	new->start_img3 = mlx_get_data_addr(new->img3_ptr, &(new->bpp),
			&(new->size_line), &(new->endian));*/
}

t_wolf	*create_struct()
{
	t_wolf  *new;

	if ((new = (t_wolf*)malloc(sizeof(t_wolf))) == 0)
		check_error_n_exit(1, "Didn't create wold sctruct");
	if ((new->player = (t_player*)malloc(sizeof(t_player))) == 0)
	{
		free(new);
		check_error_n_exit(1, "Didn't create player");
	}
	new->player->x = 3;
	new->player->y = 3;
	new->player->angle = 0;
	init_mlx(new);
	read_map(new, "map");
	create_new_map(new);
	new->limit = new->width * new->heigth;
	new->map = change_map(new);
	return(new);
}
