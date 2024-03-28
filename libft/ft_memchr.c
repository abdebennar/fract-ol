/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abennar <abennar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 22:25:45 by abennar           #+#    #+#             */
/*   Updated: 2023/11/17 01:36:58 by abennar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*b;

	b = (char *)s;
	while (n--)
	{
		if (*b == (char)c)
			return ((void *)b);
		b++;
	}
	return (NULL);
}
