/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vctadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thorker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 16:03:33 by thorker           #+#    #+#             */
/*   Updated: 2019/01/22 15:47:21 by thorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vector	*ft_vctadd(t_vector **begin, double x, double y, double z)
{
	t_vector *new_vector;
	t_vector *curr;

	if (begin == 0)
		return (0);
	if (*begin == 0)
	{
		if ((new_vector = ft_vctnew(x, y, z)) == 0)
			return (0);
		else
			return (new_vector);
	}
	curr = *begin;
	while (curr->next != 0)
		curr = curr->next;
	if ((new_vector = ft_vctnew(x, y, z)) == 0)
		return (0);
	(curr)->next = new_vector;
	return (*begin);
}
