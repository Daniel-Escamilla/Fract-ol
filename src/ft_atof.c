/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: descamil <descamil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 18:04:30 by descamil          #+#    #+#             */
/*   Updated: 2024/11/22 17:25:48 by descamil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

double	ft_deci(double number, char *str, int i)
{
	double	decimal;

	decimal = 0.1;
	if (str[i] == '-' && ++i > 0)
		return (3);
	while (ft_isdigit(str[++i]) == 1)
	{
		number = number + (str[i] - '0') * decimal;
		decimal *= 0.1;
	}
	return (number);
}

double	ft_atof(char *str)
{
	int		i;
	int		minus;
	double	number;

	i = 0;
	minus = 1;
	number = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '.')
		return (3);
	if (str[i] == '-' && ++i > 0)
		minus = -1;
	while (ft_isdigit(str[i]) == 1)
		number = number * 10.0 + (str[i++] - '0');
	if (str[i] == '.')
		number = ft_deci(number, str, i);
	return (number * minus);
}
