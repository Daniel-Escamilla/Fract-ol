/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_mandel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: descamil <descamil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:03:56 by descamil          #+#    #+#             */
/*   Updated: 2024/09/17 14:04:16 by descamil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

// long	ft_make_mandel(t_data *img)
// {
// 	int		i;
// 	double	z_real;
// 	double	z_imag;
// 	double	z_temp;
// 	long	color;

// 	img->c_real = img->min_x + (img->x / img->size) * (img->max_x - img->min_x);
// 	img->c_imag = img->min_y + (img->y / img->size) * (img->max_y - img->min_y);
// 	z_real = 0.0;
// 	z_imag = 0.0;
// 	i = 0;
// 	// if ((img->x >= img->quare.x_min_p && img->x <= img->quare.x_max_p && img->y >= img->quare.y_min_p && img->y <= img->quare.y_max_p) || (img->x >= img->quare.x_min_g && img->x <= img->quare.x_max_g && img->y >= img->quare.y_min_g && img->y <= img->quare.y_max_g))
// 	// 	color = 0x000000;			17.14	34.63
// 	// else
// 	// {
// 		while ((z_real * z_real + z_imag * z_imag) < 4.0 && i < img->max_iterations)
// 		{
// 			z_temp = z_real * z_real - z_imag * z_imag + img->c_real;
// 			z_imag = 2.0 * z_real * z_imag + img->c_imag;
// 			z_real = z_temp;
// 			i++;
// 		}
// 		color = ft_color(i, img);
// 	// }
// 	return (color);
// }


long ft_make_mandel(t_data *img)
{
    double z_real, z_imag, z_real2, z_imag2;
    int i;
    long color;

    img->c_real = img->min_x + (img->x / img->size) * (img->max_x - img->min_x);
    img->c_imag = img->min_y + (img->y / img->size) * (img->max_y - img->min_y);

    // Comprobación rápida para el conjunto principal
    if ((img->c_real + 1) * (img->c_real + 1) + img->c_imag * img->c_imag < 0.0625)
        return ft_color(img->max_iterations, img);

    // Comprobación para el cardioide
    double q = (img->c_real - 0.25) * (img->c_real - 0.25) + img->c_imag * img->c_imag;
    if (q * (q + (img->c_real - 0.25)) < 0.25 * img->c_imag * img->c_imag)
        return ft_color(img->max_iterations, img);

    z_real = z_imag = z_real2 = z_imag2 = 0.0;
    
    for (i = 0; i < img->max_iterations; i++)
    {
        z_imag = 2.0 * z_real * z_imag + img->c_imag;
        z_real = z_real2 - z_imag2 + img->c_real;
        
        z_real2 = z_real * z_real;
        z_imag2 = z_imag * z_imag;

        if (z_real2 + z_imag2 > 4.0)
            break;

        // Comprobación de periodicidad (opcional, puede ralentizar en algunos casos)
        // if (i > 20 && (z_real2 + z_imag2) < 0.000001)
        //     return ft_color(img->max_iterations, img);
    }

    color = ft_color(i, img);
    return color;
}