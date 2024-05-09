/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdhaibi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 13:24:44 by rdhaibi           #+#    #+#             */
/*   Updated: 2024/04/25 13:49:39 by rdhaibi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t		l;
	const char	*s2;

	l = ft_strlen(s1);
	s2 = malloc((sizeof(char) * l) + 1);
	if (s2 == NULL)
		return (NULL);
	ft_strlcpy((char *)s2, s1, l + 1);
	return ((char *)s2);
}
