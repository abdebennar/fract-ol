/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abennar <abennar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:15:43 by abennar           #+#    #+#             */
/*   Updated: 2024/01/27 15:11:14 by abennar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static const char	*skp(const char *str, int *sign)
{
	*sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
	{
		*sign = -1;
		str++;
	}
	else if (*str == '+')
	{
		str++;
	}
	while (*str == '0')
		str++;
	return (str);
}

int	ft_atoi(const char *s)
{
	int				sign;
	long long		number;
	int				digit_c;

	digit_c = 0;
	number = 0;
	s = skp(s, &sign);
	while (*s >= '0' && *s <= '9')
	{
		digit_c++;
		if (number > 9223372036854775807 || digit_c > 19)
		{
			if (sign == 1)
				return (-1);
			else
				return (0);
		}
		else
		{
			number = number * 10 + *s - '0';
		}
		s++;
	}
	return (sign * (int)number);
}
