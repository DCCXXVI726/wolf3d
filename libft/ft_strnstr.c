/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thorker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 17:26:05 by thorker           #+#    #+#             */
/*   Updated: 2018/11/25 15:27:11 by thorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t i;
	size_t k;

	i = 0;
	while (*(s1 + i) != '\0' && i < len)
	{
		k = 0;
		while (*(s1 + i + k) == *(s2 + k) && i + k < len && *(s2 + k) != '\0')
			k++;
		if (*(s2 + k) == '\0')
			return ((char*)(s1 + i));
		i++;
	}
	return (0);
}
