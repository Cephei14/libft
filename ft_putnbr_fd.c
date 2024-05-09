/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdhaibi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 15:07:51 by rdhaibi           #+#    #+#             */
/*   Updated: 2024/05/01 15:31:48 by rdhaibi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putchar(char c, int fd)
{
	write(fd, &c, 1);
}

static void	print_nb(int nb, int fd)
{
	int	x;
	int	y;

	x = nb / 10;
	y = nb % 10;
	if (x > 9)
		ft_putnbr_fd(x, fd);
	else
		ft_putchar(x + '0', fd);
	ft_putchar(y + '0', fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (fd < 0)
		return ;
	if (n == 2147483647)
	{
		write (fd, "2147483647", 10);
		return ;
	}
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write (fd, "-", 1);
		n = -n;
	}
	if (n < 10)
	{
		n = n + '0';
		write (fd, &n, 1);
	}
	else
		print_nb(n, fd);
}
