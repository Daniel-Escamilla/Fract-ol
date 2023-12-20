/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: descamil <descamil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 16:21:00 by descamil          #+#    #+#             */
/*   Updated: 2023/11/21 18:34:57 by descamil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

/*
int main()
{
	const char *cadena = "teste";
	int caracter = 'e';
	char *resultado = ft_strchr(cadena, caracter);
	if (resultado != NULL)
		printf("%c, en la posicion %ld.\n", caracter,resultado - cadena);
	else
		printf("%c, no está.\n", caracter);
	return (0);
}
*/
