/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: descamil <descamil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:08:51 by descamil          #+#    #+#             */
/*   Updated: 2023/12/20 18:12:22 by descamil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

int	ft_make_bonus(t_data *img)
{
	long	color;
	double	z_real;
	double	z_imag;
	double	z_temp;
	int		i;

	img->c_real = img->MIN_X + (img->x / img->size) * (img->MAX_X - img->MIN_X);
	img->c_imag = img->MIN_Y + (img->y / img->size) * (img->MAX_Y - img->MIN_Y);
	i = 0;
	z_real = img->c_real;
	z_imag = img->c_imag;
	while (i < img->max_iterations && z_real * z_real + z_imag * z_imag < 512)
	{
		img->rest = (z_real * z_real + z_imag * z_imag) * (z_real * z_real + z_imag * z_imag);
		z_temp = 2.0 / 3 * z_real + (z_real * z_real - z_imag * z_imag) / 3 / img->rest;
		z_imag = 2.0 / 3 * z_imag * (1 - z_real / img->rest);
		z_real = z_temp;
		i++;	
	}
	color = ft_color(i, img);
	return (color);
}

//*		NEWTON		*//

// f (z)	= z3 - 1
// f'(z)	= 3z^2
// Z -> z - R * (f / f')

//*		NEWTON		*//

//*		NOVA		*//

// f (z)	= z^p - 1
// f'(z)	= p * z^p-1
// Z -> z - R * (f / f')

//
//

// p = 2.0
// R = 1.0

// img->c_real = img->MIN_X + (img->x / img->size) * (img->MAX_X - img->MIN_X);
// img->c_imag = img->MIN_Y + (img->y / img->size) * (img->MAX_Y - img->MIN_Y);

// c_ri = c_real + c_imag

// Z0 = c_ri - R

// Zn+1 = c_ri - R * (c_ri^p - 1 / 2 * c_ri)

//*		NOVA		*//


// Fractal Nova que es parecida a el fractal de Newton //
// Fractal Elecho de Barnsley //



//*		BARNSLEY	*//

	///	Buscar	///

//*		BARNSLEY	*//