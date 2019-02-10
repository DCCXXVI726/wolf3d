/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thorker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 15:10:36 by thorker           #+#    #+#             */
/*   Updated: 2019/02/01 16:26:04 by thorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t k;

	k = 0;
	while (*(src + k) != '\0' && k < len)
	{
		*(dst + k) = *(src + k);
		k++;
	}
	if (k < len)
	{
		while (k < len)
		{
			*(dst + k) = '\0';
			k++;
		}
	}
	return (dst);
}
