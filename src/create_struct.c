/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfalmer- <bfalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 17:39:10 by thorker           #+#    #+#             */
/*   Updated: 2019/03/09 15:08:46 by thorker          ###   ########.fr       */
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

static void	add_textures(t_wolf *new)
{
	if ((new->tx = (t_texture*)malloc(sizeof(t_texture) * 5)) == 0)
		check_error_n_exit(1, "Didn't create texture struct");
	new->tx->img_ptr = mlx_xpm_file_to_image(new->mlx_ptr,
			"textures/WALL1.xpm", &new->tx->width, &new->tx->heidth);
	new->tx->start_img = mlx_get_data_addr(new->tx->img_ptr,
			&new->tx->bpp, &new->tx->size_line, &new->tx->endian);
	(new->tx + 1)->img_ptr = mlx_xpm_file_to_image(new->mlx_ptr,
			"textures/WALL0.xpm", &(new->tx + 1)->width,
			&((new->tx + 1)->heidth));
	(new->tx + 1)->start_img = mlx_get_data_addr((new->tx + 1)->img_ptr,
			&(new->tx + 1)->bpp, &(new->tx + 1)->size_line,
			&((new->tx + 1)->endian));
	(new->tx + 2)->img_ptr = mlx_xpm_file_to_image(new->mlx_ptr,
			"textures/hand.xpm", &((new->tx + 2)->width),
			&((new->tx + 2)->heidth));
	(new->tx + 2)->start_img = mlx_get_data_addr((new->tx + 2)->img_ptr,
			&((new->tx + 2)->bpp), &((new->tx + 2)->size_line),
			&((new->tx + 2)->endian));
	(new->tx + 3)->img_ptr = mlx_xpm_file_to_image(new->mlx_ptr,
			"textures/WALL2.xpm", &((new->tx + 3)->width),
			&((new->tx + 3)->heidth));
	(new->tx + 3)->start_img = mlx_get_data_addr((new->tx + 3)->img_ptr,
			&((new->tx + 3)->bpp), &((new->tx + 3)->size_line),
			&((new->tx + 3)->endian));
	(new->tx + 4)->img_ptr = mlx_xpm_file_to_image(new->mlx_ptr,
			"textures/WALL3.xpm", &((new->tx + 4)->width),
			&((new->tx + 4)->heidth));
	(new->tx + 4)->start_img = mlx_get_data_addr((new->tx + 4)->img_ptr,
			&((new->tx + 4)->bpp), &((new->tx + 4)->size_line),
			&((new->tx + 4)->endian));
}

static void	init_mlx(t_wolf *new)
{
	new->mlx_ptr = mlx_init();
	new->win_ptr = mlx_new_window(new->mlx_ptr, new->win_width, new->win_heidth,
			"Wolf3d");
	new->img_ptr = mlx_new_image(new->mlx_ptr, new->win_width, new->win_heidth);
	new->start_img = mlx_get_data_addr(new->img_ptr, &(new->bpp),
			&(new->size_line), &(new->endian));
	add_textures(new);
}

t_wolf		*create_struct(void)
{
	t_wolf	*new;

	if ((new = (t_wolf*)malloc(sizeof(t_wolf))) == 0)
		check_error_n_exit(1, "Didn't create wold sctruct");
	if ((new->player = (t_player*)malloc(sizeof(t_player))) == 0)
		check_error_n_exit(1, "Didn't create player");
	new->player->x = 1.5;
	new->player->y = 1.5;
	new->win_width = 1500;
	new->win_heidth = 1000;
	new->player->angle = 0;
	new->move_forward = 0;
	new->move_back = 0;
	new->move_right = 0;
	new->move_left = 0;
	new->step = 0.01;
	new->step_ill = 0;
	new->step_count = 0;
	gettimeofday(&new->time, NULL);
	init_mlx(new);
	read_map(new, "map");
	new->fov = 3.14 / 3;
	new->iteration = 1000;
	new->menu = 0;
	new->menu_string = 1;
	return (new);
}
