/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abennar <abennar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 17:38:35 by abennar           #+#    #+#             */
/*   Updated: 2023/11/21 12:19:29 by abennar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*m_block;

	if ((long)count < 0 && (long)size < 0)
		return (NULL);
	m_block = malloc(count * size);
	if (!m_block)
		return (NULL);
	else
		ft_bzero(m_block, count * size);
	return ((void *)m_block);
}
