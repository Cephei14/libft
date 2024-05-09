/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdhaibi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 15:03:51 by rdhaibi           #+#    #+#             */
/*   Updated: 2024/04/25 12:17:02 by rdhaibi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	sign(const char *str, long int *i)
{
	if (str[*i] == '+' || str[*i] == '-')
	{
		(*i)++;
		if (!ft_isdigit((char)str[*i]))
			return (0);
		if (str[*i - 1] == '-')
			return (-1);
	}
	return (1);
}

static int	lenn(const char *str, long int i)
{
	long int	l;

	l = 1;
	while (ft_isdigit(str[i]))
	{
		l = l * 10;
		i++;
	}
	return (l / 10);
}

static int	assign(const char *str, long int i, long int l)
{
	long int	n;

	n = 0;
	while (l)
	{
		n = n + (str[i] - '0') * l;
		i++;
		l /= 10;
	}
	return (n);
}

int	ft_atoi(const char *str)
{
	long int	i;
	long int	n;
	long int	l;

	i = 0;
	while (((str[i] >= 9 && str[i] <= 13) || (str[i] == 32)) && str[i])
		i++;
	n = sign(str, &i);
	while (str[i] == '0' && str[i])
		i++;
	if (n == 0)
		return (0);
	l = lenn(str, i);
	return (n * assign(str, i, l));
}
