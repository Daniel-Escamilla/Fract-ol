/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: descamil <descamil@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 11:23:29 by descamil          #+#    #+#             */
/*   Updated: 2023/10/07 11:58:45 by descamil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*arr;
	unsigned int	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	arr = (char *)malloc(sizeof(char) * (ft_strlen(s)) + 1);
	if (arr == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		arr[i] = f(i, s[i]);
		i++;
	}
	arr[i] = '\0';
	return (arr);
}
/*
char to_up(unsigned int i, char s)
{
	s = s + 1;
	return (s);
}

int main()
{
	char *str = "aaaa";
	char *ptr;

	ptr = ft_strmapi(str, to_up);
	printf("Cadena: %s", ptr);

	printf("\n");
	return 0;
}
*/