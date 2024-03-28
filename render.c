/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abennar <abennar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 15:52:55 by abennar           #+#    #+#             */
/*   Updated: 2024/02/14 04:31:10 by abennar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	my_put_pixel(int x, int y, int color, t_img img)
{
	int	offset;

	offset = (y * img.s_len) + (x * (img.bpp / 8));
	*(int *)(img.data_ptr + offset) = color;
}

static void	check_pixel(int x, int y, t_fract_ol *fract)
{
	if (ft_strcmp(fract->name, "mandelbrot") == 0)
		mandelbrot_set(x, y, fract);
	else if (ft_strcmp(fract->name, "julia") == 0)
		julia_set(x, y, fract);
	if (BONUS)
	{
		if (ft_strcmp(fract->name, "ship") == 0)
			ship_set(x, y, fract);
	}
}

void	fract_render(t_fract_ol *fract)
{
	int	x;
	int	y;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			check_pixel(x, y, fract);
			++y;
		}
		++x;
	}
	mlx_put_image_to_window(fract->mlx, fract->win, fract->img.img, 0, 0);
}
