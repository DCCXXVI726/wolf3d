/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfalmer- <bfalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 17:39:10 by thorker           #+#    #+#             */
/*   Updated: 2019/03/19 16:30:47 by thorker          ###   ########.fr       */
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
		if (new->width != -1 && new->width != (int)ft_strlen(line))
			check_error_n_exit(1, "Strings in map aren't equal");
		new->width = ft_strlen(line);
		old_tmp = tmp;
		tmp = ft_strjoin(tmp, line);
		free(old_tmp);
		free(line);
	}
	new->heigth = ft_strlen(tmp) / new->width;
	close(fd);
	new->map = tmp;
}

static void	change_texture(t_wolf *new, int index, char *name)
{
	if (((new->tx + index)->img_ptr = mlx_xpm_file_to_image(new->mlx_ptr,
		name, &((new->tx + index)->width), &((new->tx + index)->heidth))) == 0)
		check_error_n_exit(1, "Invalid texture name in parametr");
	(new->tx + index)->start_img = mlx_get_data_addr((new->tx + index)->img_ptr,
		&((new->tx + index)->bpp),
			&((new->tx + index)->size_line), &((new->tx + index)->endian));
}

static void	add_textures(t_wolf *new)
{
	if ((new->tx = (t_texture*)malloc(sizeof(t_texture) * 6)) == 0)
		check_error_n_exit(1, "Didn't create texture struct");
	change_texture(new, 0, "textures/WALL0.xpm");
	change_texture(new, 1, "textures/WALL1.xpm");
	change_texture(new, 2, "textures/hand.xpm");
	change_texture(new, 3, "textures/WALL2.xpm");
	change_texture(new, 4, "textures/WALL3.xpm");
	change_texture(new, 5, "textures/menu2.xpm");
}

static void	feel_struct(t_wolf *new)
{
	new->fov[0] = 1;
	new->fov[1] = 3.14 / 3;
	new->fov[2] = 3.14 / 4;
	new->fov[3] = 3.14 / 6;
	new->mouse_speed[0] = 3;
	new->mouse_speed[1] = 10;
	new->mouse_speed[2] = 15;
	new->mouse_speed[3] = 5;
	new->player->x = 1.5;
	new->player->y = 1.5;
	new->win_width = 1500;
	new->win_heidth = 800;
	new->player->angle = 0;
	new->move_forward = 0;
	new->move_back = 0;
	new->move_right = 0;
	new->move_left = 0;
	new->step = 0.03;
	new->step_ill = 0;
	new->step_count = 0;
	new->mouse_x = -1;
	new->width = -1;
}

t_wolf		*create_struct(char *map_name)
{
	t_wolf	*new;

	if ((new = (t_wolf*)malloc(sizeof(t_wolf))) == 0)
		check_error_n_exit(1, "Didn't create wold sctruct");
	if ((new->player = (t_player*)malloc(sizeof(t_player))) == 0)
		check_error_n_exit(1, "Didn't create player");
	if ((new->fov = (double*)malloc(sizeof(double) * 3)) == 0)
		check_error_n_exit(1, "Didn't create fov_array");
	if ((new->mouse_speed = (int*)malloc(sizeof(int) * 3)) == 0)
		check_error_n_exit(1, "Didn't create mouse_speed");
	gettimeofday(&new->time, NULL);
	feel_struct(new);
	new->mlx_ptr = mlx_init();
	new->win_ptr = mlx_new_window(new->mlx_ptr, new->win_width, new->win_heidth,
			"Wolf3d");
	new->img_ptr = mlx_new_image(new->mlx_ptr, new->win_width, new->win_heidth);
	new->start_img = mlx_get_data_addr(new->img_ptr, &(new->bpp),
			&(new->size_line), &(new->endian));
	add_textures(new);
	read_map(new, map_name);
	check_map(new);
	new->iteration = 400;
	new->menu = 0;
	new->menu_string = 1;
	return (new);
}
