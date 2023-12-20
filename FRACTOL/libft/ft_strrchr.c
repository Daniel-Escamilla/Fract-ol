/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: descamil <descamil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 17:15:59 by descamil          #+#    #+#             */
/*   Updated: 2023/11/21 18:35:42 by descamil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	while (i + 1 >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i--;
	}
	return (NULL);
}

/*
int main()
{
	const char *cadena = "La m frase";
	int caracter = 'm';
	char *resultado = ft_strrchr(cadena, caracter);

	if (resultado != NULL)
		printf("%c, en la posición %ld.\n", caracter,cadena - resultado);
	else	
		printf("%c, no está.\n", caracter);
	return (0);
}
*/
