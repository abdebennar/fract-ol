/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abennar <abennar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 14:32:26 by abennar           #+#    #+#             */
/*   Updated: 2023/11/28 14:38:22 by abennar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr( char const *str, unsigned int start, size_t len)
{
	int		i;
	char	*s_str;

	i = 0 ;
	if (!str)
		return (NULL);
	if (start > ft_strlen(str))
		return (ft_strdup(""));
	if (len > ft_strlen(str + start))
		len = ft_strlen(str + start);
	s_str = malloc(sizeof(char) * (len + 1));
	if (!s_str)
		return (NULL);
	while (len--)
	{
		s_str[i] = (start + str)[i];
		i++;
	}
	s_str[i] = '\0';
	return (s_str);
}
