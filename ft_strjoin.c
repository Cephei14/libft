/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdhaibi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 15:09:14 by rdhaibi           #+#    #+#             */
/*   Updated: 2024/04/25 15:24:00 by rdhaibi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	size_t	l1;
	size_t	l2;
	char	*str;

	i = -1;
	j = -1;
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	str = malloc(sizeof(char) * (l1 + l2) + 1);
	if (str == NULL)
		return (NULL);
	while (++i < l1)
		str[i] = s1[i];
	while (i < (l1 + l2))
	{
		str[i] = s2[++j];
		i++;
	}
	str[i] = '\0';
	return (str);
}
