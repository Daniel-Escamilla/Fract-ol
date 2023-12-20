/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_mandel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: descamil <descamil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:03:56 by descamil          #+#    #+#             */
/*   Updated: 2023/12/20 16:06:56 by descamil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

long	ft_make_mandel(t_data *img)
{
	int		i;
	double	z_real;
	double	z_imag;
	double	z_temp;
	long	color;
	
	img->c_real = img->MIN_X + (img->x / img->size) * (img->MAX_X - img->MIN_X);
	img->c_imag = img->MIN_Y + (img->y / img->size) * (img->MAX_Y - img->MIN_Y);
	
	z_real = 0.0;
	z_imag = 0.0;
	i = 0;
	while((z_real * z_real + z_imag * z_imag) < 4.0 && i < img->max_iterations)
	{
		z_temp = z_real * z_real - z_imag * z_imag + img->c_real;
		z_imag = 2.0 * z_real * z_imag + img->c_imag;
		z_real = z_temp;
		i++;
	}
	color = ft_color(i, img);
	return (color);
}
