/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ship_set.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abennar <abennar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 02:53:36 by abennar           #+#    #+#             */
/*   Updated: 2024/02/14 03:21:46 by abennar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	ship_set(int x, int y, t_fract_ol *fract)
{
	t_complex	c;
	t_complex	z;
	int			i;
	int			color;

	z.i = (scale(x, WIDTH, fract->start.r, fract->end.r) + fract->shift_x);
	z.r = (scale(y, HEIGHT, fract->start.i, fract->end.i) + fract->shift_y);
	c.i = z.i;
	c.r = z.r;
	i = 0;
	while (i < ETER)
	{
		z = sum_c(sqr_c(abs_c(z)), c);
		if ((z.i * z.i) + (z.r * z.r) > 4)
		{
			color = DARK_TEAL * (fract->cnv * i % 255);
			my_put_pixel(x, y, color, fract->img);
			return ;
		}
		i++;
	}
	my_put_pixel(x, y, BLACK, fract->img);
}
