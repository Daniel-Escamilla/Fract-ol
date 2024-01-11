/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: descamil <descamil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 18:24:40 by descamil          #+#    #+#             */
/*   Updated: 2024/01/09 18:30:04 by descamil         ###   ########.fr       */
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
	close(img->fd2);
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
	else if (key == 22)
		img->color2 = 2047;
	else if (key == 23)
		img->color2 = 1282;
	else if (key == 25)
		img->color2 += 5;
	else if (key == 26)
		img->color2 = 263172;
	else if (key == 28)
		img->color2 = 65793;
	else if (key == 29)
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
	}
	else if (key == 126)
	{
		img->min_y += 0.5 * 0.1 * img->rango_y;
		img->max_y += 0.5 * 0.1 * img->rango_y;
	}
	// printf("rango_x	%f\n", img->rango_x);
	// printf("rango_y	%f\n", img->rango_y);
	if (img->max_x <= img->zero || img->min_x >= -img->zero
		|| img->max_y <= img->zero || img->min_y >= -img->zero)
		return ;
}

void ft_frames(int key, t_data *img)
{
	if (key != 49)
		return ;
	else
	{
		char	*line;
		char	**valores;
		// int		i;

		// i = 0;
		// while (i <= 120)
		// {
			if (img->frame_i == 1)
				line = get_next_line(img->fd2);
			line = get_next_line(img->fd2);
			if (line == NULL)
				return ;
			valores = ft_split(line, ' ');
			free(line);
			if (valores[0] == NULL || valores[1] == NULL)
				return ;
			img->c_julia_r = ft_atof(valores[0]);
			img->c_julia_i = ft_atof(valores[1]);
			if ((img->c_julia_r < -2.0 || img->c_julia_r > 2.0)
				|| (img->c_julia_i < -2.0 || img->c_julia_i > 2.0))
			{
				write (1, "Cambia los parametros del archivo\n", 35);
				return ;
			}
			// draw_fractal(img);
			// usleep(10000000);
		// 	i++;
		// 	img->frame_i = i;
		// }
	}
}

int key_hook(int key, t_data *img)
{
	printf("Tecla: %d\n", key);
	if (key == 53)
		end_program(img);
	// if (key == 49)
	// {
	ft_frames(key, img);
	// 	return (0);
	// }
	ft_arrows(key, img);
	ft_change_colors(key, img);
	draw_fractal(img);
	return (0);
}
