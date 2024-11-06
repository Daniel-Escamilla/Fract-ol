/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: descamil <descamil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 17:20:42 by descamil          #+#    #+#             */
/*   Updated: 2024/01/08 17:04:59 by descamil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	n;
	char	*ptr;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	n = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	ptr = malloc(n + 1);
	if (ptr == NULL)
		return (NULL);
	while ((char)s1[i] != '\0')
	{
		ptr[i] = (char)s1[i];
		i++;
	}
	while ((char)s2[j] != '\0')
	{
		ptr[i] = (char)s2[j];
		i++;
		j++;
	}
	ptr[i] = '\0';
	return (ptr);
}

// int main()
// {
// 	const char *s1 = "Hola";
// 	const char *s2 = "Adios";
// 	char *ptr;

// 	ptr = ft_strjoin(s1, s2);

// 	printf("Join: %s\n", ptr);
// 	free(ptr);
// 	return (0);
// }
