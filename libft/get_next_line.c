/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thorker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 18:40:26 by thorker           #+#    #+#             */
/*   Updated: 2019/02/05 22:08:06 by thorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

t_file	*ft_find_file(const int fd, t_file **file)
{
	t_file	*curr;

	curr = *file;
	while (curr != NULL)
	{
		if (curr->fd == fd)
			return (curr);
		curr = curr->next;
	}
	if ((curr = (t_file*)malloc(sizeof(t_file))) == NULL)
		return (0);
	if ((curr->line = ft_strnew(BUFF_SIZE)) == NULL)
	{
		free(curr);
		return (0);
	}
	curr->readed = BUFF_SIZE;
	curr->index = 0;
	curr->fd = fd;
	curr->next = *file;
	*file = curr;
	return (curr);
}

char	*ft_my_realloc(char **line, t_file **curr, size_t i)
{
	char	*new_line;

	new_line = ft_strnew(ft_strlen(*line) + i - (*curr)->index);
	if (new_line == NULL)
	{
		free(*line);
		*line = NULL;
		return (0);
	}
	new_line = ft_strcpy(new_line, *line);
	new_line = ft_strncat(new_line, (*curr)->line + (*curr)->index, \
			i - (*curr)->index);
	free(*line);
	(*curr)->index = ++i;
	*line = new_line;
	return (*line);
}

int		ft_my_cat2(t_file **curr, char **line, size_t *i)
{
	while (*i < BUFF_SIZE && *((*curr)->line + *i) != '\0')
	{
		if (*((*curr)->line + *i) == '\n')
		{
			if ((*line = ft_my_realloc(line, curr, *i)) == NULL)
				return (-1);
			return (1);
		}
		(*i)++;
	}
	return (2);
}

int		ft_my_cat(t_file **curr, char **line)
{
	size_t	i;
	int		re;

	if ((*curr)->readed == 0)
		return (0);
	if ((*curr)->readed == EOF)
		return (-1);
	i = (*curr)->index;
	if ((re = ft_my_cat2(curr, line, &i)) != 2)
		return (re);
	if ((*line = ft_my_realloc(line, curr, i)) == NULL)
		return (-1);
	(*curr)->index = 0;
	ft_strclr((*curr)->line);
	if (((*curr)->readed = read((*curr)->fd, (*curr)->line, BUFF_SIZE)) == 0)
	{
		if (ft_strlen(*line) == 0)
			return (0);
		return (1);
	}
	if ((*curr)->readed == EOF)
		return (-1);
	return (2);
}

int		get_next_line(const int fd, char **line)
{
	static t_file	*file;
	t_file			*curr;
	int				re;

	if (fd < 0 || line == NULL)
		return (-1);
	if ((curr = ft_find_file(fd, &file)) == NULL)
		return (-1);
	if ((*line = ft_strnew(0)) == NULL)
		return (-1);
	re = ft_my_cat(&curr, line);
	while (re == 2)
		re = ft_my_cat(&curr, line);
	if (re != 1)
	{
		ft_filedel(&file, fd);
		free(*line);
	}
	return (re);
}
