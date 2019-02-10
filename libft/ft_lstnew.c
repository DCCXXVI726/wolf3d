/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thorker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 22:08:34 by thorker           #+#    #+#             */
/*   Updated: 2019/01/20 18:14:02 by thorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	void	*ft_content;
	t_list	*new_list;

	new_list = (t_list*)malloc(sizeof(t_list));
	if (new_list == NULL)
		return (0);
	new_list->next = NULL;
	if (content == NULL)
	{
		new_list->content = NULL;
		new_list->content_size = 0;
	}
	else
	{
		ft_content = malloc(content_size);
		if (ft_content == NULL)
			return (0);
		ft_memcpy(ft_content, content, content_size);
		new_list->content = ft_content;
		new_list->content_size = content_size;
	}
	return (new_list);
}
