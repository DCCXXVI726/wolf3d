/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thorker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 17:45:20 by thorker           #+#    #+#             */
/*   Updated: 2019/01/22 15:15:10 by thorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_my_size_2(char const *s, char c)
{
	int size;
	int flag;
	int	i;

	flag = 0;
	i = 0;
	size = 0;
	while (*(s + i) != '\0')
	{
		if (*(s + i) == c)
			flag = 0;
		else
		{
			if (flag == 0)
				size++;
			flag = 1;
		}
		i++;
	}
	return (size);
}

static int	ft_my_strlen(char const *s, char c)
{
	int i;

	i = 0;
	while (*(s + i) != '\0' && *(s + i) != c)
		i++;
	return (i);
}

static int	ft_mem(char const *s, char ***str, char c)
{
	int		i;
	int		l;
	size_t	k;

	i = 0;
	l = 0;
	while (*(s + i) != '\0')
	{
		if (*(s + i) != c)
		{
			k = ft_my_strlen(s + i, c);
			*(*str + l) = ft_strsub(s, i, k);
			if (*(*str + l) == NULL)
			{
				while (l != -1)
					ft_strdel((*str + l--));
				return (0);
			}
			i = i + k;
			l++;
		}
		else
			i++;
	}
	return (1);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**str;

	if (s == NULL)
		return (0);
	str = (char**)malloc(sizeof(char*) * (ft_my_size_2(s, c) + 1));
	if (str == NULL)
		return (0);
	*(str + ft_my_size_2(s, c)) = NULL;
	if (ft_mem(s, &str, c) == 0)
	{
		free(str);
		str = NULL;
		return (0);
	}
	return (str);
}
