/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: descamil <descamil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:34:21 by descamil          #+#    #+#             */
/*   Updated: 2024/11/06 18:37:38 by descamil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"
#include <math.h>

double	ft_pow_result(double number, int pow, int neg)
{
	double	new_number;

	pow -= 1;
	new_number = number;
	while (pow-- > 0)
		new_number *= number;
	if (neg == -1)
		new_number = 1 / new_number;
	return (new_number);
}

double	ft_pow(double number, int pow)
{
	double	result;
	int		neg;
	int		m;

	m = 1;
	neg = 1;
	if (pow == 0 || number == 1)
		return (1);
	if (number == 0)
		return (0);
	if (number < 0)
	{
		m = -1;
		number *= -1;
	}
	if (pow < 0)
	{
		neg = -1;
		pow *= -1;
	}
	if (m == -1 && (pow % 2) == 0)
		m = 1;
	result = ft_pow_result(number, pow, neg);
	return (result * m);
}
