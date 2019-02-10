/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddlast.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thorker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 18:28:19 by thorker           #+#    #+#             */
/*   Updated: 2018/12/03 18:58:23 by thorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstaddlast(t_list **begin_list, t_list *new)
{
	t_list	*curr;

	if (begin_list == NULL)
		return (0);
	curr = *begin_list;
	while (curr->next != 0)
		curr = curr->next;
	curr->next = new;
	return (*begin_list);
}
