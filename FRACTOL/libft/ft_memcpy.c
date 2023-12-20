/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: descamil <descamil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:50:32 by descamil          #+#    #+#             */
/*   Updated: 2023/11/21 18:34:28 by descamil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t num)
{
	size_t		i;
	char		*dest;
	const char	*s;

	if (src == NULL && dst == NULL)
		return (NULL);
	dest = (char *)dst;
	s = (const char *)src;
	i = 0;
	while (i < num)
	{
		dest[i] = s[i];
		i++;
	}
	return (dest);
}

/*
int main()
{
	char destination[50];
	ft_memcpy(destination, "La frase", 4);
	destination[4] = '\0';

	printf("%s \n", destination);
	return (0);
}
*/
