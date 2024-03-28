/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abennar <abennar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 11:38:53 by abennar           #+#    #+#             */
/*   Updated: 2023/12/28 22:00:01 by abennar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *substr, size_t len)
{
	size_t	i;
	size_t	j;

	if (substr[0] == '\0')
	{
		return ((char *)str);
	}
	i = 0;
	while (i < len && str[i] != '\0')
	{
		j = 0;
		while (str[i + j] == substr[j] && (i + j) < len)
		{
			if (substr[j + 1] == '\0')
				return ((char *)(str + i));
			j++;
		}
		i++;
	}
	return (NULL);
}
