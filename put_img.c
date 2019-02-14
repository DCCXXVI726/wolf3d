/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thorker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 18:24:44 by thorker           #+#    #+#             */
/*   Updated: 2019/02/14 16:46:53 by thorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void		set_kernel_arg(t_wolf *wolf)
{
	wolf->ft_opencl->error |= clSetKernelArg(wolf->ft_opencl->kernel, 0, sizeof(cl_mem),
			&(wolf->ft_opencl->memobj));
	check_error_n_exit(wolf->ft_opencl->error, "SetKernelArg problem");
}

static void		fill_color(t_wolf *wolf)
{
	char *string;

	string = ft_strnew(wolf->limit * sizeof(int));
	set_kernel_arg(wolf);
	wolf->ft_opencl->error = clEnqueueNDRangeKernel(wolf->ft_opencl->command_queue, wolf->ft_opencl->kernel,
			1, 0, &(wolf->limit), 0, 0, 0, 0);
	check_error_n_exit(wolf->ft_opencl->error, "EnqueueNDRangeKernel problem");
	wolf->ft_opencl->error = clEnqueueReadBuffer(wolf->ft_opencl->command_queue, wolf->ft_opencl->memobj,
			CL_TRUE, 0, wolf->limit * sizeof(int), string, 0, 0, 0);
	check_error_n_exit(wolf->ft_opencl->error, "ReadBuffer problem");
	ft_memcpy(wolf->start_img1, string, wolf->limit * sizeof(int));
	free(string);
}

int		put_img(t_wolf *wolf)
{
	wolf->ft_opencl->memobj = clCreateBuffer(wolf->ft_opencl->context, CL_MEM_WRITE_ONLY,
			1000 * 1000 * sizeof(int), NULL, &(wolf->ft_opencl->error));
	check_error_n_exit(wolf->ft_opencl->error, "CreateBuffer problem");
	fill_color(wolf);
	mlx_put_image_to_window(wolf->mlx_ptr, wolf->win_ptr, wolf->img1_ptr, 0, 0);
	return (0);
}
