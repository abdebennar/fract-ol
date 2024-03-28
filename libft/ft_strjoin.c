/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abennar <abennar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 22:19:41 by abennar           #+#    #+#             */
/*   Updated: 2024/01/20 21:34:45 by abennar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*f_str;
	char	*r_str;
	int		s_one;
	int		s_two;

	if (!s1 || !s2)
	{
		if (!s1)
			return (ft_strdup(s2));
		if (!s2)
			return (ft_strdup(s1));
		return (NULL);
	}
	s_one = ft_strlen(s1);
	s_two = ft_strlen(s2);
	f_str = malloc(sizeof(char) * (s_one + s_two + 1));
	if (!f_str)
		return (NULL);
	r_str = f_str;
	while (s_one--)
		*(f_str++) = *(s1++);
	while (s_two--)
		*(f_str++) = *(s2++);
	*f_str = '\0';
	return (r_str);
}
