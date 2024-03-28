/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abennar <abennar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 20:30:47 by abennar           #+#    #+#             */
/*   Updated: 2023/11/17 01:38:07 by abennar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = (ft_strlen(s) + 1);
	while (s != NULL && i--)
	{
		if (s[i] == (char )c)
			return ((char *)(s + i));
	}
	return (NULL);
}
