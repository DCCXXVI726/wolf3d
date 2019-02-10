/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vctnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thorker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 15:49:52 by thorker           #+#    #+#             */
/*   Updated: 2019/01/22 15:47:40 by thorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vector	*ft_vctnew(double x, double y, double z)
{
	t_vector *vector;

	if ((vector = (t_vector*)malloc(sizeof(t_vector))) == 0)
		return (0);
	vector->x = x;
	vector->y = y;
	vector->z = z;
	vector->next = 0;
	return (vector);
}
