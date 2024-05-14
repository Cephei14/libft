/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdhaibi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 13:56:48 by rdhaibi           #+#    #+#             */
/*   Updated: 2024/04/25 14:01:59 by rdhaibi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	l;
	size_t	n;

	if (!s)
		return (NULL);
	n = ft_strlen(s);
	if (start >= n)
		return (ft_strdup(""));
	if (start + len > n)
		l = n - start;
	else
		l = len;
	str = malloc((sizeof(char) * l) + 1);
	if (str == NULL)
		return (NULL);
	ft_strlcpy(((char *)str), (s + start), l + 1);
	return (str);
}
