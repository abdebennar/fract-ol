/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abennar <abennar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 14:43:38 by abennar           #+#    #+#             */
/*   Updated: 2024/02/14 03:50:21 by abennar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	format_check(va_list args, char c)
{
	int		i;

	i = 0;
	if (c == 'c')
		i += ft_putchar(va_arg(args, int));
	else if (c == 's')
		i += ft_putstr(va_arg(args, char *));
	else if (c == '%')
		i += ft_putprsnt();
	else if (c == 'd')
		i += ft_putnbr(va_arg(args, int));
	else if (c == 'u')
		i += ft_putusg(va_arg(args, unsigned int));
	else if (c == 'i')
		i += ft_putnbr(va_arg(args, int));
	else if (c == 'x')
		i += ft_puthex((va_arg(args, int)), 'x');
	else if (c == 'X')
		i += ft_puthex((va_arg(args, int)), 'X');
	else if (c == 'p')
		i += ft_putptr(va_arg(args, unsigned long));
	return (i);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	va_list	args;

	i = 0;
	va_start(args, format);
	if (write(1, "", 0) < 0)
		return (-1);
	while (*format)
	{
		if (*format == '%')
		{
			i += format_check(args, *(format + 1));
			format++;
		}
		else
			i += ft_putchar(*format);
		format++;
	}
	va_end(args);
	return (i);
}
