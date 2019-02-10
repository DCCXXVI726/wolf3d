/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thorker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 15:33:16 by thorker           #+#    #+#             */
/*   Updated: 2018/11/27 22:34:22 by thorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	i;

	if (s == NULL)
		return (0);
	i = 0;
	str = (char*)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (0);
	*(str + len) = '\0';
	while (i < len)
	{
		*(str + i) = *(s + start + i);
		i++;
	}
	return (str);
}
