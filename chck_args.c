/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chck_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abennar <abennar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 11:04:49 by abennar           #+#    #+#             */
/*   Updated: 2024/02/14 03:31:17 by abennar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

static void	dsplay_help(int x)
{
	ft_printf("\n");
	ft_printf("            Welcome to Fractal Explorer!\n");
	ft_printf("  -------------------------------------------------- \n");
	ft_printf("   mandelbrot    : display the Mandelbrot fractal\n");
	ft_printf("   julia [1] [2] : display the Julia fractal\n");
	if (BONUS)
	{
		ft_printf("   ship          : display boring_ship fratal\n");
	}
	ft_printf("   help          : display this help menu\n");
	ft_printf("  -------------------------------------------------- \n\n");
	exit(x);
}

static void	args_error(void)
{
	ft_putendl_fd("Error! : uncorrect values", 2);
	dsplay_help(1);
}

static void	check_values(char *str)
{
	int	i;
	int	d;

	i = 0;
	d = 0;
	while (str[i])
	{
		if ((str[i] >= '0' && str[i] <= '9')
			|| str[i] == '.' || str[i] == '-' || str[i] == '+')
		{
			if ((str[i] == '+' || str[i] == '-') && !(ft_isdigit(str[i + 1])))
				args_error();
			if (str[i] == '.')
				d++;
		}
		i++;
	}
	if (d > 1)
		args_error();
}

void	check_args(int argc, char **argv, t_fract_ol *fract)
{
	if (argc == 2 && ft_strcmp(argv[1], "mandelbrot") == 0)
	{
		fract->name = argv[1];
	}
	else if (argc == 4 && ft_strcmp(argv[1], "julia") == 0)
	{
		fract->name = argv[1];
		check_values(argv[2]);
		check_values(argv[3]);
		fract->julia.julia_i = atodbl(argv[2]);
		fract->julia.julia_r = atodbl(argv[3]);
	}
	else if (argc == 2 && ft_strcmp(argv[1], "ship") == 0 && BONUS)
	{
		fract->name = argv[1];
	}
	else
		dsplay_help(1);
}
