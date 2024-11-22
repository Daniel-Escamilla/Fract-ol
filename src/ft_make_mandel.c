/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_mandel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: descamil <descamil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:03:56 by descamil          #+#    #+#             */
/*   Updated: 2024/11/22 16:47:36 by descamil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

int	ft_check_mandel_point(t_data *img)
{
	double	q;

	img->c_real = img->min_x
		+ (img->x / img->size) * (img->max_x - img->min_x);
	img->c_imag = img->min_y
		+ (img->y / img->size) * (img->max_y - img->min_y);
	if ((img->c_real + 1)
		* (img->c_real + 1) + img->c_imag * img->c_imag < 0.0625)
		return (1);
	q = (img->c_real - 0.25)
		* (img->c_real - 0.25) + img->c_imag * img->c_imag;
	if (q * (q + (img->c_real - 0.25)) < 0.25 * img->c_imag * img->c_imag)
		return (1);
	return (0);
}

long	ft_make_mandel(t_data *img, int i)
{
	double	z_real;
	double	z_imag;
	double	z_real2;
	double	z_imag2;
	long	color;

	if (ft_check_mandel_point(img) == 1)
		return (ft_color(img->max_iterations, img));
	z_real = 0.0;
	z_imag = 0.0;
	z_real2 = 0.0;
	z_imag2 = 0.0;
	while (z_real2 + z_imag2 <= 4.0 && i < img->max_iterations)
	{
		z_imag = 2.0 * z_real * z_imag + img->c_imag;
		z_real = z_real2 - z_imag2 + img->c_real;
		z_real2 = z_real * z_real;
		z_imag2 = z_imag * z_imag;
		i++;
	}
	color = ft_color(i, img);
	return (color);
}
