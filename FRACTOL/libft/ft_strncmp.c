/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: descamil <descamil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 18:05:21 by descamil          #+#    #+#             */
/*   Updated: 2023/11/21 18:35:29 by descamil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (s1[i] == '\0' || s2[i] == '\0' || s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}
/*
int main()
{
	const char *cadena1 = "-1";
	const char *cadena2 = "-2";
	int comparacion = ft_strncmp(cadena1, cadena2, 3);

	if (comparacion == 0)
		printf("Iguales.\n");
	else if (comparacion < 0)
		printf("Cadena2 > Cadena1.\n");
	else
		printf("Cadena1 > Cadena2.\n");
	return (0);
}
*/
