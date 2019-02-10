/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thorker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 18:08:38 by thorker           #+#    #+#             */
/*   Updated: 2018/11/28 21:27:24 by thorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int i;
	int k;
	int flag;

	i = 0;
	k = 0;
	flag = 0;
	if (c == '\0')
	{
		i = ft_strlen(s);
		return ((char*)(s + i));
	}
	while (*(s + i) != '\0')
	{
		if (*(s + i) == c)
		{
			k = i;
			flag = 1;
		}
		i++;
	}
	if (flag == 1)
		return ((char*)(s + k));
	else
		return (0);
}
