/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thorker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 14:42:53 by thorker           #+#    #+#             */
/*   Updated: 2018/11/30 17:31:59 by thorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*begin;
	t_list	*curr;
	t_list	*next;
	t_list	*new_next;

	if (lst == NULL || f == NULL)
		return (0);
	begin = (t_list*)malloc(sizeof(t_list));
	if (begin == NULL)
		return (0);
	begin = f(lst);
	curr = begin;
	lst = lst->next;
	while (lst != NULL)
	{
		next = lst->next;
		new_next = (t_list*)malloc(sizeof(t_list));
		if (new_next == NULL)
			return (0);
		new_next = f(lst);
		curr->next = new_next;
		curr = curr->next;
		lst = next;
	}
	return (begin);
}
