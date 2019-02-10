/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thorker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 19:12:56 by thorker           #+#    #+#             */
/*   Updated: 2019/01/17 12:54:34 by thorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_skip(const char *c)
{
	int i;

	i = 0;
	while (c[i] == '\n' || c[i] == '\t' || c[i] == '\v' || c[i] == ' ' ||
			c[i] == '\f' || c[i] == '\r')
		i++;
	return (i);
}

int		ft_atoi(const char *c)
{
	int			i;
	long long	re;
	int			flag;

	i = ft_skip(c);
	re = 0;
	flag = 1;
	if (*(c + i) == '-')
	{
		flag = -1;
		i++;
	}
	else if (*(c + i) == '+')
		i++;
	while (*(c + i) != '\0')
	{
		if (*(c + i) < '0' || *(c + i) > '9')
			return ((int)(re * flag));
		re = re * 10 + (*(c + i) - '0');
		if (re < 0)
			return ((int)(flag == 1 ? -1 : 0));
		i++;
	}
	return ((int)(re * flag));
}
