/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numeros_julia.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: descamil <descamil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 18:33:14 by descamil          #+#    #+#             */
/*   Updated: 2024/01/09 18:21:17 by descamil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/ft_fractol.h"

void	numbers_julia(double resolucion, double max, double min)
{
	double	num;
	double	num2;

	num = 1;
	num2 = -0.01;
	while (num >= min)
	{
		printf("%.4f %.4f\n", num, num2);
		num -= resolucion;
	}
}

int main()
{
	double	resolution = 0.025;
	double	max = 1.0;
	double	min = -2.0;

	numbers_julia(resolution, max, min);
	return (0);
}