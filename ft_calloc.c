/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdhaibi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 12:26:25 by rdhaibi           #+#    #+#             */
/*   Updated: 2024/04/25 13:20:04 by rdhaibi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	void	*ptr;

	if (size != 0 && num > SIZE_MAX / size)
	{
		errno = ENOMEM;
		return (NULL);
	}
	ptr = malloc(num * size);
	if (ptr == NULL)
	{
		errno = ENOMEM;
		return (NULL);
	}
	ft_memset(ptr, '\0', num * size);
	return (ptr);
}
