/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abennar <abennar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:28:38 by abennar           #+#    #+#             */
/*   Updated: 2023/11/17 01:37:37 by abennar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	s_len;
	size_t	d_len;

	s_len = 0;
	d_len = 0;
	s_len = ft_strlen(src);
	if (!dstsize)
		return (s_len);
	while (*dst && dstsize)
	{
		dst++;
		d_len++;
		dstsize--;
	}
	while (*src && dstsize > 1)
	{
		*dst++ = *src++;
		dstsize--;
	}
	if (dstsize != 0)
	{
		*dst = '\0';
	}
	return (d_len + s_len);
}
