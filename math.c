/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abennar <abennar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:52:38 by abennar           #+#    #+#             */
/*   Updated: 2024/02/15 22:03:19 by abennar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

t_complex	sum_c(t_complex c1, t_complex c2)
{
	t_complex	result;

	result.i = c1.i + c2.i;
	result.r = c1.r + c2.r;
	return (result);
}

t_complex	sqr_c(t_complex c)
{
	t_complex	result;

	result.i = (c.i * c.i) - (c.r * c.r);
	result.r = 2 * c.i * c.r;
	return (result);
}

t_complex	abs_c(t_complex z)
{
	t_complex	res;

	res.i = fabs(z.i);
	res.r = fabs(z.r);
	return (res);
}
