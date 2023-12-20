/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: descamil <descamil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 18:24:40 by descamil          #+#    #+#             */
/*   Updated: 2023/12/20 18:51:05 by descamil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

void	my_mlx_pixel_put(t_data *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y *img->line_length + x * (img->bits_per_pixel/8));
	*(unsigned int*)dst = color;
}

long	ft_color(int iterations, t_data *img)
{
	long color;
	int	i;

	color = img->color;
	i = 0;
	if (iterations == img->max_iterations)
		return (0);
	while (iterations > i)
	{
		if (color <= 0)
			return (0);
		color -= img->color2;
		i++;
	}
	return (color);
}

int	end_program(t_data *img)
{
	mlx_destroy_window(img->mlx, img->mlx_win);
	exit (0);
}

void	ft_change_colors(int key, t_data *img)
{
	if (key == 18)
		img->color2 = 8192;
	else if (key == 19)
		img->color2 -= 70;
	else if (key == 20)
		img->color2 += 70;
	else if (key == 21)
		img->color2 = 9252;
	else if (key == 23)
		img->color2 = 1282;
	else if (key == 22)
		img->color2 = 2047;
	else if (key == 26)
		img->color2 = 263172;
	else if (key == 28)
		img->color2 = 65793;
	else if (key == 25)
		img->color2 += 5;
	else if (key == 29)
		img->color2 = 8198;
}

void	ft_arrows(int key, t_data *img)
{
	if (key == 123)
	{
		img->MIN_X -= 0.5 * 0.1 * img->rango_x;
		img->MAX_X -= 0.5 * 0.1 * img->rango_x;
		printf("MIN_X	%f\n", img->MIN_X);
		printf("MAX_X	 %f\n", img->MAX_X);
		printf("MIN_Y	%f\n", img->MIN_Y);
		printf("MAX_Y	 %f\n", img->MAX_Y);
	}
	else if (key == 124)
	{
		img->MIN_X += 0.5 * 0.1 * img->rango_x;
		img->MAX_X += 0.5 * 0.1 * img->rango_x;
		printf("MIN_X	%f\n", img->MIN_X);
		printf("MAX_X	 %f\n", img->MAX_X);
		printf("MIN_Y	%f\n", img->MIN_Y);
		printf("MAX_Y	 %f\n", img->MAX_Y);
	}
	else if (key == 125)
	{
		img->MIN_Y -= 0.5 * 0.1 * img->rango_y;
		img->MAX_Y -= 0.5 * 0.1 * img->rango_y;
		printf("MIN_X	%f\n", img->MIN_X);
		printf("MAX_X	 %f\n", img->MAX_X);
		printf("MIN_Y	%f\n", img->MIN_Y);
		printf("MAX_Y	 %f\n", img->MAX_Y);
	}
	else if (key == 126)
	{
		img->MIN_Y += 0.5 * 0.1 * img->rango_y;
		img->MAX_Y += 0.5 * 0.1 * img->rango_y;
		printf("MIN_X	%f\n", img->MIN_X);
		printf("MAX_X	 %f\n", img->MAX_X);
		printf("MIN_Y	%f\n", img->MIN_Y);
		printf("MAX_Y	 %f\n", img->MAX_Y);
	}
	if (img->MAX_X <= img->zero || img->MIN_X >= -img->zero 
		|| img->MAX_Y <= img->zero || img->MIN_Y >= -img->zero)
		return ;
}

int key_hook(int key, t_data *img)
{
	printf("Tecla: %d\n", key);
	if (key == 53)
		end_program(img);
	ft_arrows(key, img);
	ft_change_colors(key, img);
	draw_fractal(img);
	return (0);
}
