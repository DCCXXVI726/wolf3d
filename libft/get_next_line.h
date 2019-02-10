/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thorker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 20:11:57 by thorker           #+#    #+#             */
/*   Updated: 2019/01/20 21:39:36 by thorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 1000
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct		s_file
{
	int				readed;
	int				fd;
	char			*line;
	size_t			index;
	struct s_file	*next;
}					t_file;
int					get_next_line(const int fd, char **line);
#endif
