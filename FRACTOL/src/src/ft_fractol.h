/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: descamil <descamil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 18:23:12 by descamil          #+#    #+#             */
/*   Updated: 2024/01/11 16:52:54 by descamil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FRACTOL_H
# define FT_FRACTOL_H

# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include "../gnl/get_next_line.h"
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <unistd.h>
# include <limits.h>
# include <fcntl.h>

typedef struct s_temp
{
	double	min_x;
	double	max_x;
	double	min_y;
	double	max_y;
}	t_temp;

typedef struct s_zoom
{
	int		ur;
	int		dr;
	int		ul;
	int		dl;
}	t_zoom;

typedef struct s_data
{
	t_temp	temp;
	t_zoom	zoom;
	void	*img;
	void	*mlx;
	void	*mlx_win;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	char	*name;
	int		pause;
	long	color;
	long	color2;
	double	max_iterations;
	double	x;
	double	y;
	double	size;
	double	c_julia_r;
	double	c_julia_i;
	double	c_real;
	double	c_imag;
	double	min_x;
	double	max_x;
	double	min_y;
	double	max_y;
	double	zero;
	double	rest;
	double	rango_x;
	double	rango_y;
	double	escala_x;
	double	escala_y;
}	t_data;

double	ft_atof(char *str);
double	ft_pow(double number, int pow);
int		end_program(t_data *img);
int		ft_make_bonus(t_data *img);
int		key_hook(int key, t_data *img);
int		mouse_move(int key, int x, int y, t_data *img);
int		ft_argc_4(t_data *img, char *argv2, char *argv3);
long	ft_make_julia(t_data *img);
long	ft_make_mandel(t_data *img);
long	ft_color(int iterations, t_data *img);
void	draw_fractal(t_data *img);
void	ft_set_values(t_data *img);
void	ft_old_values(t_data *img);
void	ft_new_values(t_data *img);
void	ft_create_window(t_data *img);
void	ft_arrows(int key, t_data *img);
void	ft_zoom_in(t_data *img, int x, int y);
void	ft_change_colors(int key, t_data *img);
void	ft_zoom_out(t_data *img, int x, int y);
void	ft_change_center(t_data *img, int x, int y);
void	ft_mouse_center(int x, int y, t_data *img, int key);
void	my_mlx_pixel_put(t_data *img, int x, int y, int color);

#endif