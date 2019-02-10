/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thorker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 16:10:26 by thorker           #+#    #+#             */
/*   Updated: 2018/11/26 19:22:10 by thorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*c1;
	unsigned char	*c2;

	c1 = (unsigned char*)dst;
	c2 = (unsigned char*)src;
	if (c1 > c2)
	{
		i = len;
		while (i--)
			*(c1 + i) = *(c2 + i);
	}
	else if (c1 != c2)
	{
		i = -1;
		while (++i < len)
			*(c1 + i) = *(c2 + i);
	}
	return (dst);
}
