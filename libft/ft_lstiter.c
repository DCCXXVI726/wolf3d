/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thorker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 14:36:32 by thorker           #+#    #+#             */
/*   Updated: 2018/11/29 14:40:57 by thorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list	*curr;
	t_list	*next;

	curr = lst;
	while (curr != NULL && f != NULL)
	{
		next = curr->next;
		f(curr);
		curr = next;
	}
}
