/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: descamil <descamil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:06:31 by descamil          #+#    #+#             */
/*   Updated: 2023/11/21 18:34:41 by descamil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char	*ptr;
	char	caracter;
	int		i;

	ptr = (char *)s;
	caracter = (char)c;
	i = 0;
	while (n != 0)
	{
		ptr[i] = caracter;
		n--;
		i++;
	}
	return (ptr);
}
/*
int main ()
{
	char str[] = "La frase";
	ft_memset(str, 'H', 3);
	printf("%s \n", str);
	return (0);
}
*/
