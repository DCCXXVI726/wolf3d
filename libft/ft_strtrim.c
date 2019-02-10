/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thorker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 16:33:39 by thorker           #+#    #+#             */
/*   Updated: 2018/11/27 22:26:02 by thorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_my_size(char const *s, int *i)
{
	int size;

	size = *i;
	*i = *i - 1;
	while (*(s + *i) == ' ' || *(s + *i) == '\t' || *(s + *i) == '\n')
	{
		*i = *i - 1;
		size--;
		if (*i == 0)
			return (0);
	}
	*i = 0;
	while (*(s + *i) == ' ' || *(s + *i) == '\t' || *(s + *i) == '\n')
	{
		*i = *i + 1;
		size--;
	}
	return (size);
}

char		*ft_strtrim(char const *s)
{
	int		i;
	char	*str;
	int		size;
	int		k;

	if (s == NULL)
		return (0);
	i = 0;
	while (*(s + i) != '\0')
		i++;
	size = ft_my_size(s, &i);
	if (size < 0)
		size = 0;
	str = (char*)malloc(sizeof(char) * (size + 1));
	if (str == NULL)
		return (0);
	*(str + size) = '\0';
	k = 0;
	while (k < size)
	{
		*(str + k) = *(s + i + k);
		k++;
	}
	return (str);
}
