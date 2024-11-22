/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: descamil <descamil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 18:24:40 by descamil          #+#    #+#             */
/*   Updated: 2024/11/22 17:44:14 by descamil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

void	my_mlx_pixel_put(t_data *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

long	ft_color(int iterations, t_data *img)
{
	long	color;
	int		i;

	color = img->color;
	i = 0;
	if (iterations == img->max_iterations)
		return (0);
	while (iterations > i)
	{
		if (color == 1677726)
			return (0);
		color += img->color2;
		i++;
	}
	return (color);
}

void	ft_change_colors(int key, t_data *img)
{
	if (key == ONE)
		img->color2 = 4096;
	else if (key == TWO)
		img->color2 -= 128;
	else if (key == THREE)
		img->color2 += 128;
	else if (key == FOUR)
		img->color2 = 16;
	else if (key == FIVE)
		img->color2 = 2048;
	else if (key == SIX)
		img->color2 = 1024;
	else if (key == SEVEN)
		img->color2 += 1;
	else if (key == EIGHT)
		img->color2 = 131072;
	else if (key == NINE)
		img->color2 = 65536;
	else if (key == ZERO)
		img->color2 = 262144;
}

void	ft_arrows(int key, t_data *img)
{
	if (key == LEFT)
	{
		img->min_x -= 0.5 * 0.1 * img->rango_x;
		img->max_x -= 0.5 * 0.1 * img->rango_x;
	}
	else if (key == RIGHT)
	{
		img->min_x += 0.5 * 0.1 * img->rango_x;
		img->max_x += 0.5 * 0.1 * img->rango_x;
	}
	else if (key == UP)
	{
		img->min_y -= 0.5 * 0.1 * img->rango_y;
		img->max_y -= 0.5 * 0.1 * img->rango_y;
	}
	else if (key == DOWN)
	{
		img->max_y += 0.5 * 0.1 * img->rango_y;
		img->min_y += 0.5 * 0.1 * img->rango_y;
	}
}

int	key_hook(int key, t_data *img)
{
	if (key == 65307)
		end_program(img);
	ft_arrows(key, img);
	ft_change_colors(key, img);
	draw_fractal(img);
	return (0);
}
