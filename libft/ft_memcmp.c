/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: descamil <descamil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 16:23:42 by descamil          #+#    #+#             */
/*   Updated: 2023/11/21 18:34:25 by descamil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*v1;
	const unsigned char	*v2;

	i = 0;
	v1 = (const unsigned char *)s1;
	v2 = (const unsigned char *)s2;
	while (i < n)
	{
		if (v1[i] == v2[i])
			i++;
		else
			return (v1[i] - v2[i]);
	}
	return (0);
}

/*
int main()
{
	const unsigned char s1[] = "Esta es";
	const unsigned char s2[] = "Esta no es";
	size_t n = 6;

	int result = memcmp(s1, s2, n);
	if (result > 0)
		printf("S1 es mayor que S2.\n");
	else if (result	< 0)
		printf("S1 es menor que S2.\n");
	else
		printf("S1 es igual que S2.\n");
	return (0);
}
*/
