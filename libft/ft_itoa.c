/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thorker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 19:54:13 by thorker           #+#    #+#             */
/*   Updated: 2019/03/19 16:17:27 by thorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_my_size_3(int n)
{
	int i;

	i = 0;
	if (n == -2147483648)
		return (11);
	if (n == 0)
		return (1);
	if (n < 0)
	{
		i++;
		n = n * (-1);
	}
	while (n != 0)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

char		*ft_itoa(int n)
{
	int		size;
	char	*str;

	size = ft_my_size_3(n);
	str = (char*)malloc(sizeof(char) * (size + 1));
	if (str == NULL)
		return (0);
	*(str + size) = '\0';
	if (n == 0)
		*(str) = '0';
	if (n < 0)
		*(str) = '-';
	size--;
	while (n != 0)
	{
		if (n % 10 < 0)
			*(str + size) = '0' - n % 10;
		else
			*(str + size) = '0' + n % 10;
		n = n / 10;
		size--;
	}
	return (str);
}
