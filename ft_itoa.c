/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdhaibi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:12:54 by rdhaibi           #+#    #+#             */
/*   Updated: 2024/05/01 13:23:56 by rdhaibi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(int n, int *s)
{
	int	l;

	if (n > 0)
		(*s) = 0;
	else
	{
		(*s) = 1;
		n = -n;
	}
	l = 0;
	while (n > 0)
	{
		n = n / 10;
		l++;
	}
	if (*s == 1)
		return (l + 1);
	return (l);
}

static char	*limit(int n)
{
	char	*str;

	if (n == 0)
		str = "0";
	else if (n == -2147483648)
		str = "-2147483648";
	else
		str = NULL;
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		j;
	int		s;

	j = ft_intlen(n, &s);
	i = j;
	if (limit(n))
		return (ft_strdup(limit(n)));
	str = malloc((sizeof (char)) * j + 1);
	if (str == NULL)
		return (NULL);
	if (s == 1)
		n = -n;
	while (--i > -1)
	{
		str[i] = ((n % 10) + '0');
		n = n / 10;
	}
	if (s == 1)
	str[0] = '-';
	str[j] = '\0';
	return (str);
}
