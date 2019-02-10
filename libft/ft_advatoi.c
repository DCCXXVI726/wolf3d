/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advatoi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thorker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 12:29:07 by thorker           #+#    #+#             */
/*   Updated: 2019/01/17 14:45:53 by thorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_atoibase(const char *c, int base)
{
	char	*symb_base;
	int		i;
	int		num;
	int		k;

	i = 0;
	num = 0;
	symb_base = ft_strdup("0123456789ABCDEF");
	while (*(c + i) != 0)
	{
		k = 0;
		while (k < base)
		{
			if (*(c + i) == *(symb_base + k))
			{
				num = num * base + *(c + i) - '0';
				break ;
			}
			k++;
		}
		if (k == base)
			return (num);
		i++;
	}
	return (num);
}

int			ft_advatoi(const char *c)
{
	int i;
	int num;

	i = ft_skip(c);
	if (*(c + i) == '0')
	{
		if (*(c + i + 1) == 'x')
			num = ft_atoibase(c + i + 2, 16);
		else
			num = ft_atoibase(c + i + 1, 8);
	}
	else
		num = ft_atoi(c + i);
	return (num);
}
