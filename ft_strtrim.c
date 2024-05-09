/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdhaibi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 11:18:52 by rdhaibi           #+#    #+#             */
/*   Updated: 2024/04/26 14:29:21 by rdhaibi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	occurence(char const *s1, char const *set, int l, char c)
{
	int	i;

	i = 0;
	if (c == '+')
	{
		while (s1[i] != '\0' && ft_strchr(set, s1[i]))
			i++;
		return (i);
	}
	if (c == '-')
	{
		while (ft_strchr(set, s1[l - 1]))
			l--;
		return (l);
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int	l;
	int	begin;
	int	end;

	if (!s1)
		return (NULL);
	l = ft_strlen((char *) s1);
	begin = occurence(s1, set, l, '+');
	if (begin == l)
		return (ft_strdup(""));
	end = occurence(s1, set, l, '-');
	return (ft_substr(s1, begin, end - begin));
}
