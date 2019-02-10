/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcount.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thorker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 18:02:34 by thorker           #+#    #+#             */
/*   Updated: 2018/12/03 18:59:17 by thorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstcount(t_list *begin_list)
{
	int		count;
	t_list	*curr;

	count = 0;
	if (begin_list == NULL)
		return (0);
	curr = begin_list;
	while (curr != NULL)
	{
		curr = curr->next;
		count++;
	}
	return (count);
}
