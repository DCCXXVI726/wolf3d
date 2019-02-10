/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thorker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 15:44:24 by thorker           #+#    #+#             */
/*   Updated: 2019/02/01 16:05:23 by thorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	k;

	if (s1 == NULL || s2 == NULL)
		return (0);
	i = ft_strlen(s1);
	k = 0;
	while (*(s2 + k) != '\0')
		k++;
	str = (char*)malloc(sizeof(char) * (i + k + 1));
	if (str == NULL)
		return (0);
	*(str + i + k) = '\0';
	i = 0;
	while (*(s1 + i) != '\0')
	{
		*(str + i) = *(s1 + i);
		i++;
	}
	k = -1;
	while (*(s2 + ++k) != '\0')
		*(str + i + k) = *(s2 + k);
	return (str);
}
