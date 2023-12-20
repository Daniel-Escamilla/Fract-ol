/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: descamil <descamil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 18:23:12 by descamil          #+#    #+#             */
/*   Updated: 2023/12/20 17:30:40 by descamil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FRACTOL_H
# define FT_FRACTOL_H

#include "../mlx/mlx.h"
#include "../libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct s_temp
{
	double	MIN_X;
	double	MAX_X;
	double	MIN_Y;
	double	MAX_Y;
}	t_temp;

typedef struct s_data
{
	void	*img;
	void	*mlx;
	void	*mlx_win;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	char	*name;
	int		argc;
	long	color;
	long	color2;
	double	max_iterations;
	double	x;
	double 	y;
	double	cx;
	double	cy;
	double	size;
	double	c_julia_r;
	double	c_julia_i;
	double	c_real;
	double	c_imag;
	double	MIN_X;
	double	MAX_X;
	double	MIN_Y;
	double	MAX_Y;
	double	zoom;
	double	zoom_factor;
	double	rest;
	double	zero;
	double	rango_x;
	double	rango_y;
	t_temp	temp;
}	t_data;

double	ft_atof(char *str);
double  ft_pow(double number, int pow);
long	ft_make_julia(t_data *img);
long	ft_make_mandel(t_data *img);
long	ft_color(int i, t_data *img);
int		end_program(t_data *img);
int		ft_make_bonus(t_data *img);
int		key_hook(int keycode, t_data *img);
void	draw_fractal(t_data *img);
void	ft_set_values(t_data *img);
void	ft_create_window(t_data *img);
void	my_mlx_pixel_put(t_data *img, int x, int y, int color);

#endif