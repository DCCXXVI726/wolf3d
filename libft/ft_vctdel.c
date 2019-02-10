/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vctdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thorker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 16:11:15 by thorker           #+#    #+#             */
/*   Updated: 2019/01/22 15:43:49 by thorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_vctdel(t_vector **begin)
{
	t_vector *curr;
	t_vector *next;

	if (begin == NULL)
		return ;
	curr = *begin;
	while (curr != 0)
	{
		next = curr->next;
		free(curr);
		curr = next;
	}
	*begin = NULL;
}
