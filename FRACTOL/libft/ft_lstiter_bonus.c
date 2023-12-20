/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: descamil <descamil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 18:21:13 by descamil          #+#    #+#             */
/*   Updated: 2023/11/21 18:34:12 by descamil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (lst != NULL)
	{
		while (lst != NULL)
		{
			f(lst->content);
			lst = lst->next;
		}
	}
}
/*
void	print_content(void *data)
{
	printf("%s\n", (char *)data);
}

int main()
{
	t_list *lista = NULL;
	char *data1 = "Emental1";
	char *data2 = "Emental2";
	t_list *node1 = ft_lstnew(data1);
	t_list *node2 = ft_lstnew(data2);

	node1->next = node2;
	node2->next = NULL;

	ft_lstiter(node1, print_content);
	free(node1);
	free(node2);

	return (0);
}
*/