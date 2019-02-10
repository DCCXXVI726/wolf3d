/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thorker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 15:17:44 by thorker           #+#    #+#             */
/*   Updated: 2018/11/29 17:21:14 by thorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *d, const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*c1;
	unsigned char	*c2;

	c1 = (unsigned char*)d;
	c2 = (unsigned char*)s;
	i = 0;
	while (i < n)
	{
		*(c1 + i) = *(c2 + i);
		if (*(c2 + i) == (unsigned char)(c))
			return ((void*)c1 + i + 1);
		i++;
	}
	return (0);
}
