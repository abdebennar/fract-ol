/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abennar <abennar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 11:39:13 by abennar           #+#    #+#             */
/*   Updated: 2023/12/28 21:37:14 by abennar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(unsigned int nb)
{
	int	len;

	len = 0;
	while (nb != 0)
	{
		len++;
		nb = nb / 16;
	}
	return (len);
}

static void	ft_hex(unsigned int nb, char x)
{
	if (nb >= 16)
	{
		ft_hex(nb / 16, x);
		ft_hex(nb % 16, x);
	}
	else if (nb < 10)
	{
		ft_putchar(nb + 48);
	}
	else
	{
		if (x == 'x')
			ft_putchar(nb - 10 + 'a');
		else if (x == 'X')
			ft_putchar(nb - 10 + 'A');
	}
}

int	ft_puthex(unsigned int nb, char x)
{
	if (nb == 0)
		return (write(1, "0", 1));
	else
		ft_hex(nb, x);
	return (ft_len(nb));
}
