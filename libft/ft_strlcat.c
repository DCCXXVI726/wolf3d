/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thorker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 13:54:36 by thorker           #+#    #+#             */
/*   Updated: 2018/11/28 20:01:34 by thorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *s1, const char *s2, size_t size)
{
	size_t i;
	size_t k;
	size_t a;

	i = ft_strlen(s1);
	k = ft_strlen(s2);
	if (i > size)
		return (size + k);
	a = k;
	k = 0;
	while (*(s2 + k) != '\0' && i + k < size - 1)
	{
		*(s1 + i + k) = *(s2 + k);
		k++;
	}
	*(s1 + i + k) = '\0';
	return (a + i);
}
