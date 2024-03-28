/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abennar <abennar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 12:58:40 by abennar           #+#    #+#             */
/*   Updated: 2023/12/28 21:37:52 by abennar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(unsigned long ptr)
{
	int	len;

	len = 0;
	while (ptr != 0)
	{
		len++;
		ptr = ptr / 16;
	}
	return (len);
}

static void	ft_hex(unsigned long ptr)
{
	if (ptr >= 16)
	{
		ft_hex(ptr / 16);
		ft_hex(ptr % 16);
	}
	else
	{
		if (ptr < 10)
			ft_putchar(ptr + '0');
		else
			ft_putchar(ptr - 10 + 'a');
	}
}

int	ft_putptr(unsigned long ptr)
{
	int	len;

	len = 0;
	len += ft_putstr("0x");
	if (ptr == 0)
		len += ft_putchar('0');
	else
		ft_hex(ptr);
	len += ft_len(ptr);
	return (len);
}
