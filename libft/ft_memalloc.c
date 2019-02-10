/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thorker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 21:53:10 by thorker           #+#    #+#             */
/*   Updated: 2018/11/29 17:20:27 by thorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char	*c;

	c = (unsigned char*)malloc(size);
	if (c == NULL)
		return (NULL);
	while (size--)
		*(c + size) = 0;
	return ((void*)c);
}
