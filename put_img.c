/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thorker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 18:24:44 by thorker           #+#    #+#             */
/*   Updated: 2019/02/14 20:30:04 by thorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void		put_player(t_wolf *wolf)
{
	int x;
	int y;
	int i;
	int k;

	x = (int)wolf->player->x;
	y = (int)wolf->player->y;
	k = -5;
	ft_putnbrln(x);
	ft_putnbrln(y);
	while (k < 5)
	{
		i = -5;
		while (i < 5)
		{
			if ((i + x >= 0) && (i + x < 1000) && (k + y >= 0) && (k + y < 1000))
				((int*)wolf->start_img1)[(y + k)  * 1000 + x + i] = 0xFF0000;
			i++;
		}
		k++;
	}
	x += 10 * cos(wolf->player->angle);
	y += 10 * sin(wolf->player->angle);
	k = -3;
	while (k < 3)
	{
		i = -3;
		while (i < 3)
		{
			if ((i + x >= 0) && (i + x < 1000) && (k + y >= 0) && (k + y < 1000))
				((int*)wolf->start_img1)[(y + k)  * 1000 + x + i] = 0xFFFF00;
			i++;
		}
		k++;
	}
}
static void		set_kernel_arg(t_wolf *wolf)
{
	wolf->ft_opencl->error |= clSetKernelArg(wolf->ft_opencl->kernel, 0, sizeof(cl_mem),
			&(wolf->ft_opencl->memobj));
	wolf->ft_opencl->error |= clSetKernelArg(wolf->ft_opencl->kernel, 1, sizeof(cl_mem),
			&(wolf->cl_map));
	wolf->ft_opencl->error |= clSetKernelArg(wolf->ft_opencl->kernel, 2, sizeof(int),
			&(wolf->width));
	check_error_n_exit(wolf->ft_opencl->error, "SetKernelArg problem");
}

static void		fill_color(t_wolf *wolf)
{
	char *string;

	string = ft_strnew(1000 * 1000 * sizeof(int));
	set_kernel_arg(wolf);
	wolf->ft_opencl->error = clEnqueueNDRangeKernel(wolf->ft_opencl->command_queue, wolf->ft_opencl->kernel,
			1, 0, &(wolf->limit), 0, 0, 0, 0);
	check_error_n_exit(wolf->ft_opencl->error, "EnqueueNDRangeKernel problem");
	wolf->ft_opencl->error = clEnqueueReadBuffer(wolf->ft_opencl->command_queue, wolf->ft_opencl->memobj,
			CL_TRUE, 0, 1000 * 1000 * sizeof(int), string, 0, 0, 0);
	check_error_n_exit(wolf->ft_opencl->error, "ReadBuffer problem");
	ft_memcpy(wolf->start_img1, string, 1000 * 1000 * sizeof(int));
	free(string);
}

int		put_img(t_wolf *wolf)
{
	wolf->ft_opencl->memobj = clCreateBuffer(wolf->ft_opencl->context, CL_MEM_WRITE_ONLY,
			1000 * 1000 * sizeof(int), NULL, &(wolf->ft_opencl->error));
	check_error_n_exit(wolf->ft_opencl->error, "CreateBuffer problem");
	wolf->cl_map = clCreateBuffer(wolf->ft_opencl->context, CL_MEM_WRITE_ONLY,
			wolf->limit, NULL, &(wolf->ft_opencl->error));
	check_error_n_exit(wolf->ft_opencl->error, "CreateBuffer problem");
	wolf->ft_opencl->error = clEnqueueWriteBuffer(wolf->ft_opencl->command_queue, wolf->cl_map,
			CL_TRUE, 0, wolf->limit, wolf->map, 0, 0, 0);
	check_error_n_exit(wolf->ft_opencl->error, "WriteBuffer problem");
	fill_color(wolf);
	put_player(wolf);
	mlx_put_image_to_window(wolf->mlx_ptr, wolf->win_ptr, wolf->img1_ptr, 0, 0);
	return (0);
}
