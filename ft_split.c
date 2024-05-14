/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdhaibi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 14:37:44 by rdhaibi           #+#    #+#             */
/*   Updated: 2024/04/30 14:33:28 by rdhaibi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*edges(char const *s, char c, int *i)
{
	int	l1;
	int	l2;

	while (s[*i] == c)
		(*i)++;
	l1 = *i;
	while (s[*i] != '\0' && s[*i] != c)
		(*i)++;
	l2 = *i;
	return (ft_substr(s, l1, l2 - l1));
}

static int	wordsnum(char const *s, char c)
{
	int	n;

	n = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			n++;
			while (*s && *s != c)
				s++;
		}
	}
	return (n);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	**str;

	if (!s)
		return (NULL);
	str = malloc ((sizeof(char *)) * (wordsnum(s, c) + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (j < wordsnum(s, c))
	{
		str[j] = edges(s, c, &i);
		if (!str[j])
		{
			while (j--)
				free(str[j]);
			free(str);
			return (NULL);
		}
		j++;
	}
	str[j] = NULL;
	return (str);
}
