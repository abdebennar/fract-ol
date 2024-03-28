/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abennar <abennar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 23:35:47 by abennar           #+#    #+#             */
/*   Updated: 2023/11/08 00:43:20 by abennar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const	void *s1, const void *s2, size_t n)
{
	const unsigned char	*s_one;
	const unsigned char	*s_two;

	s_one = s1;
	s_two = s2;
	while (n--)
	{
		if (*s_one != *s_two)
			return (*s_one - *s_two);
		s_one++;
		s_two++;
	}
	return (0);
}
