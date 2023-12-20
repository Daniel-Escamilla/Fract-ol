/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_julia.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: descamil <descamil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:07:47 by descamil          #+#    #+#             */
/*   Updated: 2023/12/20 19:22:22 by descamil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

long	ft_make_julia(t_data *img)
{
	int		iterations;
	double	z_real;
	double	z_imag;
	double	z_temp;
	long	color;

	if (img->c_julia_r == 0.000000 && img->c_julia_i == 0.000000)
	{
		img->c_julia_r = -0.766667;	// img.c_julia_r = -0.1;
		img->c_julia_i = -0.09;		// img.c_julia_i = 0.87;
	}
	z_real = img->MIN_X + (img->x / img->size) * (img->MAX_X - img->MIN_X);
	z_imag = img->MIN_Y + (img->y / img->size) * (img->MAX_Y - img->MIN_Y);
	iterations = 0;
	while((z_real * z_real + z_imag * z_imag) < 4.0 && iterations < img->max_iterations)
	{
		z_temp = z_real * z_real - z_imag * z_imag + img->c_julia_r;
		z_imag = 2.0 * z_real * z_imag + img->c_julia_i;
		z_real = z_temp;
		iterations++;
	}
	color = ft_color(iterations, img);
	return (color);
}
