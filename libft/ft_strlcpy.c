/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: descamil <descamil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 16:30:08 by descamil          #+#    #+#             */
/*   Updated: 2024/01/08 17:05:24 by descamil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t len_dest)
{
	size_t	i;

	i = 0;
	if (len_dest <= ft_strlen(src))
	{
		if (len_dest == 0)
			return (ft_strlen(src));
		while (len_dest > 1)
		{
			dest[i] = src[i];
			len_dest--;
			i++;
		}
		dest[i] = '\0';
		return (ft_strlen(src));
	}
	i = 0;
	while (i < len_dest - 1 && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (i);
}
/*
int main()
{
	char dest[] = "Esta es la frase";
	char str[] = "Esta es la";

	ft_strlcpy(dest, str, sizeof(dest));
	
	if (strcmp(dest, str) == 0)
	{
		printf("Sí\n");
		printf("%s\n", dest);
	}
	else
		printf("No\n");
	return (0);
}
*/
