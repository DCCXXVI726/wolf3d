/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thorker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 22:20:13 by thorker           #+#    #+#             */
/*   Updated: 2019/02/01 16:07:55 by thorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*c;
	size_t	i;

	c = (char*)malloc(sizeof(char) * (size + 1));
	if (c == NULL)
		return (0);
	i = 0;
	while (i <= size)
	{
		*(c + i) = '\0';
		i++;
	}
	return (c);
}
