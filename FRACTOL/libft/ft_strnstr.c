/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: descamil <descamil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 17:01:54 by descamil          #+#    #+#             */
/*   Updated: 2024/01/09 16:59:49 by descamil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	if (*s2 == '\0')
		return (0);
	while (s1[i] != '\0' && i < len)
	{
		if (s1[i] == s2[j])
		{
			k = i;
			while (s1[k] == s2[j] && s2[j] != '\0' && (k < len))
			{
				k++;
				j++;
				if (s2[j] == '\0')
					return (1);
			}
			j = 0;
		}
		i++;
	}
	return (0);
}

/*
int main()
{
	const char *s1 = "Esta es la frase";
	const char *s2 = "ta e";
	size_t len = 5;
	char *result = ft_strnstr(s1, s2, len);
	
	if (result != NULL)
		printf ("'%s' encontrado en '%s' en la posicion %ld.\n", s2, s1, result - s1);
	else
		printf ("'%s' no se encontro en '%s'.\n", s2, s1);

	char *result2 = strnstr(s1, s2, len);

	if (result2 != NULL)
		printf ("'%s' encontrado en '%s' en la posicion %ld.\n", s2, s1, result - s1);
	else
		printf ("'%s' no se encontro en '%s'.\n", s2, s1);
	return (0);
}
*/
