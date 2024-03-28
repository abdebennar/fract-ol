/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abennar <abennar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 15:43:26 by abennar           #+#    #+#             */
/*   Updated: 2024/02/14 03:32:10 by abennar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

static void	values_init(t_fract_ol *fract)
{
	fract->zoom = 0.1;
	fract->cnv = 1;
	fract->shift_x = 0.0;
	fract->shift_y = 0.0;
	fract->start.i = -2;
	fract->start.r = 2;
	fract->end.r = -2;
	fract->end.i = 2;
}

void	fract_init(t_fract_ol *fract)
{
	fract->mlx = mlx_init();
	if (!fract->mlx)
		exit(1);
	fract->win = mlx_new_window(fract->mlx, WIDTH, HEIGHT, fract->name);
	if (!fract->win)
	{
		free(fract->mlx);
		exit(1);
	}
	fract->img.img = mlx_new_image(fract->mlx, WIDTH, HEIGHT);
	if (!fract->img.img)
	{
		mlx_destroy_window(fract->mlx, fract->win);
		free(fract->mlx);
		exit(1);
	}
	fract->img.data_ptr = mlx_get_data_addr(fract->img.img,
			&fract->img.bpp, &fract->img.s_len, &fract->img.endian);
	if (!fract->img.data_ptr)
	{
		mlx_destroy_image(fract->mlx, fract->img.img);
		mlx_destroy_window(fract->mlx, fract->win);
		exit(1);
	}
	values_init(fract);
}
