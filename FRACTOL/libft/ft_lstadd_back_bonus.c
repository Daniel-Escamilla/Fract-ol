/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: descamil <descamil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 15:02:34 by descamil          #+#    #+#             */
/*   Updated: 2023/11/21 18:34:02 by descamil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*current_list;

	current_list = *lst;
	if (current_list == NULL)
	{
		*lst = new;
		return ;
	}
	while (current_list->next != NULL)
		current_list = current_list->next;
	current_list->next = new;
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

	t_list *actual = lista;
	while (actual != NULL)
	{
		printf("%s\n", (char *)actual->content);
		actual = actual->next;
	}
	return (0);
}
*/