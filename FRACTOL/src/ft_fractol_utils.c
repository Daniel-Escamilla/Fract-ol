/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: descamil <descamil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 18:24:40 by descamil          #+#    #+#             */
/*   Updated: 2024/06/05 12:07:39 by descamil         ###   ########.fr       */
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
		if (color <= 0)
			return (0);
		color -= img->color2;
		i++;
	}
	return (color);
}

void	ft_change_colors(int key, t_data *img)
{
	if (key == 49)
		img->color2 = 8192;
	else if (key == 50)
		img->color2 -= 70;
	else if (key == 51)
		img->color2 += 70;
	else if (key == 52)
		img->color2 = 9252;
	else if (key == 53)
		img->color2 = 2047;
	else if (key == 54)
		img->color2 = 1282;
	else if (key == 55)
		img->color2 += 5;
	else if (key == 56)
		img->color2 = 263172;
	else if (key == 57)
		img->color2 = 65793;
	else if (key == 58)
		img->color2 = 8198;
}

void	ft_arrows(int key, t_data *img)
{
	if (key == 123)
	{
		img->min_x -= 0.5 * 0.1 * img->rango_x;
		img->max_x -= 0.5 * 0.1 * img->rango_x;
	}
	else if (key == 124)
	{
		img->min_x += 0.5 * 0.1 * img->rango_x;
		img->max_x += 0.5 * 0.1 * img->rango_x;
	}
	else if (key == 125)
	{
		img->min_y -= 0.5 * 0.1 * img->rango_y;
		img->max_y -= 0.5 * 0.1 * img->rango_y;
		img->max_y += 0.5 * 0.1 * img->rango_y;
	}
	if (img->max_x <= img->zero || img->min_x >= -img->zero
		|| img->max_y <= img->zero || img->min_y >= -img->zero)
		return ;
}

int	key_hook(int key, t_data *img)
{
	printf("%d\n", key);
	if (key == 65307)
		end_program(img);
	ft_arrows(key, img);
	ft_change_colors(key, img);
	draw_fractal(img);
	return (0);
}
