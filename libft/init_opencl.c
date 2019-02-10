/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_opencl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thorker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 16:10:21 by thorker           #+#    #+#             */
/*   Updated: 2019/02/10 19:15:22 by thorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void        load_kernel2(char **tmp, char **old_tmp, int fd)
{
	if (ft_strlen(*tmp) != 0)
	{
		*old_tmp = *tmp;
		*tmp = ft_strjoin(*old_tmp, "\n");
		free(*old_tmp);
	}
	else
		ft_strdel(tmp);
	close(fd);
}

static char        *load_kernel(char *name)
{
	int        fd;
	char    *line;
	char    *tmp;
	char    *old_tmp;
	int        gnl;

	tmp = ft_strnew(0);
	if ((fd = open(name, O_RDONLY)) < 0)
		check_error_n_exit(1, "Didn't open file");
	while ((gnl = get_next_line(fd, &line)) != 0)
	{
		if (gnl < 0)
			check_error_n_exit(1, "Didn't read file");
		old_tmp = tmp;
		tmp = ft_strjoin(old_tmp, "\n");
		free(old_tmp);
		old_tmp = tmp;
		tmp = ft_strjoin(old_tmp, line);
		free(line);
		free(old_tmp);
	}
	load_kernel2(&tmp, &old_tmp, fd);
	return (tmp);
}

static void        init_opencl2(t_opencl *ft_opencl, char *name_func)
{
	ft_opencl->program = clCreateProgramWithSource(ft_opencl->context,
			1, (const char **)&(ft_opencl->src_kernel_str),
			(const size_t *)&(ft_opencl->src_kernel_size), &(ft_opencl->error));
	check_error_n_exit(ft_opencl->error, "CreateProgramWithSource problem");
	ft_opencl->error = clBuildProgram(ft_opencl->program, 0, 0, 0, 0, 0);
	check_error_n_exit(ft_opencl->error, "BuildProgram problem");
	ft_opencl->kernel = clCreateKernel(ft_opencl->program, name_func, &(ft_opencl->error));
	check_error_n_exit(ft_opencl->error, "CreateKernel problem");
}

static t_opencl		*create_struct(void)
{
	t_opencl	*new;

	if ((new = (t_opencl*)malloc(sizeof(t_opencl))) == 0)
		return (0);
	new->device_id = 0;
	new->error = 0;
	new->context = 0;
	new->command_queue = 0;
	new->memobj = 0;
	new->program = 0;
	new->kernel = 0;
	new->src_kernel_str = 0;
	new->src_kernel_size = 0;
	return (new);
}

t_opencl		*init_opencl(char *name_file, char *name_func)
{
	t_opencl	*ft_opencl;

	if ((ft_opencl = create_struct()) == 0)
		check_error_n_exit(1, "Didn't create struct for OpenCL");
	ft_opencl->src_kernel_str = load_kernel(name_file);
	ft_opencl->src_kernel_size = ft_strlen(ft_opencl->src_kernel_str);
	ft_opencl->error = clGetDeviceIDs(0, CL_DEVICE_TYPE_GPU, 1, &(ft_opencl->device_id), 0);
	check_error_n_exit(ft_opencl->error, "GetDeviceIDS problem");
	ft_opencl->context = clCreateContext(0, 1, &(ft_opencl->device_id), 0, 0,
			&(ft_opencl->error));
	check_error_n_exit(ft_opencl->error, "CreateContext problem");
	ft_opencl->command_queue = clCreateCommandQueue(ft_opencl->context, ft_opencl->device_id,
			0, &(ft_opencl->error));
	check_error_n_exit(ft_opencl->error, "CreateCommandQueue problem");
	init_opencl2(ft_opencl, name_func);
	return (ft_opencl);
}
