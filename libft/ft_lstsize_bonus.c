/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: descamil <descamil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:38:21 by descamil          #+#    #+#             */
/*   Updated: 2023/11/21 18:34:21 by descamil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	while (lst != NULL)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}
/*
int main()
{
	t_list	*lista = NULL;
	char	*data1 = "Element1";
	char	*data2 = "Element2";
	t_list	*node1 = ft_lstnew(data1);
	t_list	*node2 = ft_lstnew(data2);

	ft_lstadd_back(&lista, node1);
	ft_lstadd_back(&lista, node2);

	int size = ft_lstsize(lista);
	printf ("Tamaño : %d\n", size);

	return (0);
}
*/