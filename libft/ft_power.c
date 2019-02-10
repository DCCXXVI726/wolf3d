/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thorker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 17:34:08 by thorker           #+#    #+#             */
/*   Updated: 2018/12/03 17:39:28 by thorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_power(int nbr, int power)
{
	int s;

	if (nbr == 0 || power < 0)
		return (0);
	if (power == 0)
		return (1);
	s = 1;
	while (power > 0)
	{
		s = s * nbr;
		power--;
	}
	return (s);
}
