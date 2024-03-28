/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abennar <abennar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 14:28:43 by abennar           #+#    #+#             */
/*   Updated: 2024/02/14 04:24:12 by abennar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	exit_handler(t_fract_ol *fract)
{
	mlx_destroy_image(fract->mlx, fract->img.img);
	mlx_destroy_window(fract->mlx, fract->win);
	exit(0);
}

static void	convert(int	*int_prt, double *dbl_prt, char *str)
{
	double	cnv;

	cnv = 1.0;
	while (*str >= '0' && *str <= '9' && *str != '.')
		*int_prt = *int_prt * 10 + (*str++ - '0');
	if (*str == '.')
	{
		str++;
		while (*str >= '0' && *str <= '9')
		{
			cnv /= 10;
			*dbl_prt = *dbl_prt + (*str++ - '0') * cnv;
		}
	}
}

double	atodbl(char *str)
{
	int		int_prt;
	double	dbl_prt;
	int		sign;

	int_prt = 0;
	dbl_prt = 0.0;
	sign = 1;
	if (str[0] == '-' || str[0] == '+')
	{
		if (str[0] == '-')
			sign = -1;
		str++;
	}
	convert(&int_prt, &dbl_prt, str);
	return ((dbl_prt + int_prt) * sign);
}

double	scale(int value, double old_max, double new_min, double new_max)
{
	double	old_min;

	old_min = 0;
	return (((value - old_min) * (new_max - new_min))
		/ (old_max - old_min) + new_min);
}

void	re_set(t_fract_ol *fract)
{
	fract->zoom = 1.0;
	fract->cnv = 1;
	fract->shift_x = 0.0;
	fract->shift_y = 0.0;
	fract->start.i = -2;
	fract->start.r = 2;
	fract->end.r = -2;
	fract->end.i = 2;
	fract_render(fract);
}
