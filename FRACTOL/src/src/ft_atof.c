/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: descamil <descamil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 18:04:30 by descamil          #+#    #+#             */
/*   Updated: 2024/01/11 18:04:41 by descamil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

double	ft_atof(char *str)
{
	int		i;
	int		m;
	float	nb;
	float	deci;

	i = 0;
	m = 1;
	nb = 0;
	deci = 0.1;
	while (str[i] == ' ')
		i++;
	if (str[i] == '-' && str[i++])
		m = -1;
	while (str[i] && ft_isdigit(str[i]) && str[i] != '.')
		nb = nb * 10.0 + (str[i++] - '0');
	if (str[i++] == '.')
	{
		while (str[i] && ft_isdigit(str[i]))
		{
			nb = nb + (str[i++] - '0') * deci;
			deci *= 0.1;
		}
	}
	return (nb * m);
}
