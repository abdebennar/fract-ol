/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abennar <abennar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 11:03:22 by abennar           #+#    #+#             */
/*   Updated: 2024/02/14 03:29:46 by abennar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	main(int argc, char **argv)
{
	t_fract_ol	fract;

	check_args(argc, argv, &fract);
	fract_init(&fract);
	fract_render(&fract);
	events_init(&fract);
	mlx_loop(fract.mlx);
	return (0);
}
