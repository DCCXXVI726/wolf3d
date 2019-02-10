/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thorker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 17:33:50 by thorker           #+#    #+#             */
/*   Updated: 2018/11/29 17:42:08 by thorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	size_t	i;
	size_t	k;
	char	c;

	if (str == NULL)
		return (0);
	i = 0;
	k = ft_strlen(str);
	while (i < k)
	{
		c = *(str + i);
		*(str + i) = *(str + k);
		*(str + k) = c;
		i++;
		k--;
	}
	return (str);
}
