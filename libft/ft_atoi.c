/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: descamil <descamil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 16:00:38 by descamil          #+#    #+#             */
/*   Updated: 2023/11/21 18:32:11 by descamil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	m;
	int	number;

	m = 1;
	i = 0;
	number = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
	if (str[i] == '-')
	{
		m = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while ((str[i] == '-') || (str[i] == '+'))
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
	{
		number = number * 10 + (str[i] - '0');
		i++;
	}
	return (number * m);
}

// int main()
// {
// 	char str[] = "42"

// 	int solv;
// 	int solv2;

// 	solv = atoi(str);
// 	solv2 = ft_atoi(str);
// 	printf("Resultado ATOI = El número es %d.\n", solv);
// 	printf("Resultado FT_ATOI = El número es %d.\n", solv2);
// 	return (0);
// }