/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: descamil <descamil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 18:04:30 by descamil          #+#    #+#             */
/*   Updated: 2024/06/05 14:35:42 by descamil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

double	ft_deci(double nb, char *str, int i)
{
	double	deci;

	deci = 0.1;
	if (str[i] == '-' && ++i > 0)
		return (3);
	while (ft_isdigit(str[++i]) == 1)
	{
		nb = nb + (str[i] - '0') * deci;
		deci *= 0.1;
	}
	return (nb);
}

double	ft_atof(char *str)
{
	int		i;
	int		m;
	double	nb;

	i = 0;
	m = 1;
	nb = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '.')
		return (3);
	if (str[i] == '-' && ++i > 0)
		m = -1;
	while (ft_isdigit(str[i]) == 1)
		nb = nb * 10.0 + (str[i++] - '0');
	if (str[i] == '.')
		nb = ft_deci(nb, str, i);
	return (nb * m);
}
