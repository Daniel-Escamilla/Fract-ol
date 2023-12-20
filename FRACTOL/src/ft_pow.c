/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: descamil <descamil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:34:21 by descamil          #+#    #+#             */
/*   Updated: 2023/12/14 17:59:04 by descamil         ###   ########.fr       */
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

double  ft_pow(double number, int pow)
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


// number + && pow + = + > 0 5^2 = 25;
// number - && pow + % 2 == 0 = - > 0 -5^2 = 25;
// number + && pow - = + < 0 = 5^-2 = 1 / 5^2 = 0.04;
// number - && pow - = - < 0 = -5^-2 = 

// int main()
// {
//     double  number;

// 	number = ft_pow(0, 1);
//     printf("0, 1 	=	%f\n", number);
// 	number = pow(0, 1);
// 	printf("0, 1 	=	%f\n", number);
// 	number = ft_pow(0, -1);
//     printf("0, -1 	=	%f\n", number);
// 	number = pow(0, -1);
// 	printf("0, -1 	=	%f\n", number);
// 	number = ft_pow(-0, 1);
//     printf("-0, 1 	=	%f\n", number);
// 	number = pow(-0, 1);
// 	printf("-0, 1 	=	%f\n", number);
// 	number = ft_pow(-1, 0);
//     printf("-1, 0 	=	%f\n", number);
// 	number = ft_pow(1, 0);
//     printf("1, 0 	=	%f\n", number);
// 	number = pow(1, 0);
// 	printf("1, 0 	=	%f\n", number);
// 	number = pow(-1, 0);
// 	printf("-1, 0 	=	%f\n", number);
// 	number = ft_pow(1, -0);
//     printf("1, -0 	=	%f\n", number);
// 	number = pow(1, -0);
// 	printf("1, -0 	=	%f\n", number);
// 	number = ft_pow(-1, -0);
//     printf("-1, -0 	=	%f\n", number);
// 	number = pow(-1, -0);
// 	printf("-1, -0 	=	%f\n", number);
//     number = ft_pow(1, -1);
//     printf("1, -1 	=	%f\n", number);
// 	number = pow(1, -1);
// 	printf("1, -1 	=	%f\n", number);
// 	number = ft_pow(-1, 1);
//     printf("-1, 1 	=	%f\n", number);
// 	number = pow(-1, 1);
// 	printf("-1, 1 	=	%f\n", number);
// 	number = ft_pow(1, 1);
//     printf("1, 1 	=	%f\n", number);
// 	number = pow(1, 1);
// 	printf("1, 1 	=	%f\n", number);
// 	number = ft_pow(-1, -1);
//     printf("-1, -1 	=	%f\n", number);
// 	number = pow(-1, -1);
// 	printf("-1, -1 	=	%f\n", number);
// 	number = ft_pow(2, 1);
//     printf("2, 1 	=	%f\n", number);
// 	number = pow(2, 1);
// 	printf("2, 1 	=	%f\n", number);
// 	number = ft_pow(-2, 1);
//     printf("-2, 1 	=	%f\n", number);
// 	number = pow(-2, 1);
// 	printf("-2, 1 	=	%f\n", number);
// 	number = ft_pow(2, -1);
//     printf("2, -1 	=	%f\n", number);
// 	number = pow(2, -1);
// 	printf("2, -1 	=	%f\n", number);
// 	number = ft_pow(-2, -1);
//     printf("-2, -1 	=	%f\n", number);
// 	number = pow(-2, -1);
// 	printf("-2, -1 	=	%f\n", number);
// 	number = ft_pow(4, 3);
//     printf("4, 3 	=	%f\n", number);
// 	number = pow(4, 3);
// 	printf("4, 3 	=	%f\n", number);
// 	number = ft_pow(-4, 3);
//     printf("-4, 3 	=	%f\n", number);
// 	number = pow(-4, 3);
// 	printf("-4, 3 	=	%f\n", number);
// 	number = ft_pow(-4, 2);
//     printf("-4, 2 	=	%f\n", number);
// 	number = pow(-4, 2);
// 	printf("-4, 2 	=	%f\n", number);
// 	number = ft_pow(4, -3);
//     printf("4, -3 	=	%f\n", number);
// 	number = pow(4, -3);
// 	printf("4, -3 	=	%f\n", number);
// 	number = ft_pow(-4, -3);
//     printf("-4, -3 	=	%f\n", number);
// 	number = pow(-4, -3);
// 	printf("-4, -3 	=	%f\n", number);
// 	number = ft_pow(4, -2);
//     printf("4, -2 	=	%f\n", number);
// 	number = pow(4, -2);
// 	printf("4, -2 	=	%f\n", number);
// 	number = ft_pow(-4, 2);
//     printf("-4, 2 	=	%f\n", number);
// 	number = pow(-4, 2);
// 	printf("-4, 2 	=	%f\n", number);
// 	number = ft_pow(-4, -2);
//     printf("-4, -2 	=	%f\n", number);
// 	number = pow(-4, -2);
// 	printf("-4, -2 	=	%f\n", number);
//     return (0);
// }