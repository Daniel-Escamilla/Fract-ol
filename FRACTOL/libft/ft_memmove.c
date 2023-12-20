/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: descamil <descamil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 17:56:24 by descamil          #+#    #+#             */
/*   Updated: 2023/11/21 18:34:30 by descamil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*destino;
	const char	*origen;

	origen = (const char *)src;
	destino = (char *)dest;
	if (destino == NULL && origen == NULL)
		return (NULL);
	if (destino <= origen || destino >= (origen + n))
		while (n--)
			*(destino++) = *(origen++);
	else
	{
		destino += n - 1;
		origen += n - 1;
		while (n--)
			*(destino--) = *(origen--);
	}
	return (dest);
}
/*
int main()
{
	char destino[] = "Frase que se borra";
	const char origen[] = "Superposicion";

	ft_memmove(destino, origen, strlen(origen));
	printf("%s", destino);
	return 0;
}
*/
