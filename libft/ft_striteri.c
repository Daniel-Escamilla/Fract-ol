/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: descamil <descamil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 12:20:24 by descamil          #+#    #+#             */
/*   Updated: 2023/11/27 17:39:08 by descamil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	if (s == NULL)
		return ;
	while (s[i] != '\0')
	{
		f(i, s);
		i++;
	}
}

/*
void test_to_upper(unsigned int i, char *s)
{
	s[i] = ft_toupper((unsigned int)s[i]);
	return ;
}

int main()
{
	char s[] = "aaaaa";
	printf("%s\n", s);
	ft_striteri(s, test_to_upper);
	printf("%s\n", s);
	return (0);
}
*/