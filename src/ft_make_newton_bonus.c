/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_newton_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: descamil <descamil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 13:55:18 by descamil          #+#    #+#             */
/*   Updated: 2024/10/01 17:35:06 by descamil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

long	ft_color_bonus(double z_real, double z_imag)
{
	double	z1;
	double	z2;
	double	z3;

	z1 = sqrt(pow(z_real - 1, 2) + pow(z_imag, 2));
	if (z1 < 0.001)
		return (0xFF0000);
	z2 = sqrt(pow(z_real + 0.5, 2) + pow(z_imag - sqrt(3) / 2, 2));
	if (z2 < 0.001)
		return (0x00FF00);
	z3 = sqrt(pow(z_real + 0.5, 2) + pow(z_imag + sqrt(3) / 2, 2));
	if (z3 < 0.001)
		return (0x0000FF);
	return (0x000000);
}

int	ft_make_bonus(t_data *img)
{
	long	color;
	double	z_real;
	double	z_imag;
	double	z_temp;
	int		i;

	img->c_real = img->min_x + (img->x / img->size) * (img->max_x - img->min_x);
	img->c_imag = img->min_y + (img->y / img->size) * (img->max_y - img->min_y);
	i = 0;
	z_real = img->c_real;
	z_imag = img->c_imag;
	while (i < img->max_iterations && z_real * z_real + z_imag * z_imag < 512)
	{
		img->rest = (z_real * z_real + z_imag * z_imag)
			* (z_real * z_real + z_imag * z_imag);
		z_temp = 2.0 / 3 * z_real + (z_real * z_real
				- z_imag * z_imag) / 3 / img->rest;
		z_imag = 2.0 / 3 * z_imag * (1 - z_real / img->rest);
		z_real = z_temp;
		i++;
	}
	color = ft_color_bonus(z_real, z_imag);
	return (color);
}

