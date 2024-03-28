/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abennar <abennar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 15:47:37 by abennar           #+#    #+#             */
/*   Updated: 2024/02/15 22:10:04 by abennar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

# include <mlx.h>
# include <math.h>
# include "./libft/libft.h"

# define WIDTH 800
# define HEIGHT 800
# define ETER 50

# ifndef BONUS
#  define BONUS false
# endif

/*
** COLORS
*/

# define BLACK		0x000000 
# define WHITE		0xFFFFFF
# define RED		0xFF0000
# define GREEN		0x00FF00
# define BLUE		0x0000FF
# define YELLOW		0xFFFF00
# define CYAN		0x00FFFF
# define MAGENTA	0xFF00FF
# define GRAY		0x808080
# define LIGHT_GRAY	0xC0C0C0
# define DARK_GRAY	0x404040

# define DARK_TEAL	0x0B1F1F

/*
** JULIA CONSTENT
*/

typedef struct s_julia
{
	double	julia_r;
	double	julia_i;
}				t_julia;

/*
** IMG STRUCT
*/

typedef struct s_img
{
	void	*img;
	int		bpp;
	int		s_len;
	int		endian;
	char	*data_ptr;
}				t_img;

/*
** COMPLEX NUMS
*/

typedef struct s_complex
{
	double	i;
	double	r;
}				t_complex;

typedef struct s_fract_ol
{
	void		*mlx;
	void		*win;
	char		*name;
	float		zoom;
	int			cnv;
	double		shift_y;
	double		shift_x;
	t_julia		julia;
	t_complex	start;
	t_complex	end;
	t_img		img;
	double		mouse_x;
	double		mouse_y;
}				t_fract_ol;

void		check_args(int argc, char **argv, t_fract_ol *fract);
double		atodbl(char *str);

/*
* MATH 
*/

t_complex	sqr_c(t_complex	c);
t_complex	abs_c(t_complex	z);
t_complex	sum_c(t_complex	c1, t_complex c2);

void		fract_render(t_fract_ol *fract);
void		fract_init(t_fract_ol *fract);
double		scale(int value, double old_max, double new_min, double new_max);
void		events_init(t_fract_ol *fract);

/*
** FRACTALS
*/

void		ship_set(int x, int y, t_fract_ol *fract);
void		mandelbrot_set(int x, int y, t_fract_ol *fract);
void		julia_set(int y, int x, t_fract_ol *fract);

void		my_put_pixel(int x, int y, int color, t_img img);
double		get_shift(double shift, bool shift_bool);
void		re_set(t_fract_ol *fract);
int			exit_handler(t_fract_ol *fract);

#endif