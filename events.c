/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abennar <abennar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:25:44 by abennar           #+#    #+#             */
/*   Updated: 2024/02/14 03:31:56 by abennar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

static int	key_handler(int key, t_fract_ol *fract)
{
	if (key == 8)
		fract->cnv += 1;
	else if (key == 9)
		fract->cnv -= 1;
	else if (key == 123)
		fract->shift_x -= 0.1;
	else if (key == 124)
		fract->shift_x += 0.1;
	else if (key == 125)
		fract->shift_y -= 0.1;
	else if (key == 126)
		fract->shift_y += 0.1;
	else if (key == 36)
		re_set(fract);
	else if (key == 53)
		exit_handler(fract);
	fract_render(fract);
	return (0);
}

static void	zoom_follow_mouse(int x, int y, double zoom, t_fract_ol *fract)
{
	double	mouse_x;
	double	mouse_y;

	if (ft_strcmp(fract->name, "ship") == 0)
	{
		mouse_x = scale(y, WIDTH, fract->start.i, fract->end.i);
		mouse_y = scale(x, HEIGHT, fract->start.r, fract->end.r);
	}
	else
	{
		mouse_x = scale(x, WIDTH, fract->start.i, fract->end.i);
		mouse_y = scale(y, HEIGHT, fract->start.r, fract->end.r);
	}
	fract->zoom *= zoom;
	fract->start.i = (fract->start.i - mouse_x) * zoom + mouse_x;
	fract->start.r = (fract->start.r - mouse_y) * zoom + mouse_y;
	fract->end.i = (fract->end.i - mouse_x) * zoom + mouse_x;
	fract->end.r = (fract->end.r - mouse_y) * zoom + mouse_y;
}

static void	zoom_in_middle(double zoom, t_fract_ol *fract)
{
	fract->zoom *= zoom;
	fract->start.i = fract->start.i * zoom ;
	fract->start.r = fract->start.r * zoom ;
	fract->end.i = fract->end.i * zoom ;
	fract->end.r = fract->end.r * zoom ;
}

static int	mouse_handler(int button, int x, int y, t_fract_ol *fract)
{
	double	zoom;

	zoom = 1.0;
	if (button == 4 || button == 5)
	{
		if (button == 4)
		{
			fract->zoom = 0.1;
			zoom = 1 + fract->zoom;
		}
		else if (button == 5)
		{
			fract->zoom = 0.1;
			zoom = 1 - fract->zoom;
		}
		if (BONUS)
			zoom_follow_mouse(x, y, zoom, fract);
		else
			zoom_in_middle(zoom, fract);
		fract_render(fract);
	}
	return (0);
}

void	events_init(t_fract_ol *fract)
{
	mlx_hook(fract->win, 2, 1L, key_handler, fract);
	mlx_hook(fract->win, 17, (1L << 17), exit_handler, fract);
	mlx_mouse_hook(fract->win, mouse_handler, fract);
}
