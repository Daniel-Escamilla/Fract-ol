/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: descamil <descamil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:44:32 by descamil          #+#    #+#             */
/*   Updated: 2023/11/21 18:32:48 by descamil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

// int main()
// {
//     t_list	*list = NULL;
// 	char	*data1 = "Element1";
// 	char	*data2 = "Element2";
// 	t_list	*node1 = ft_lstnew(data1);
// 	t_list	*node2 = ft_lstnew(data2);

// 	ft_lstadd_back(&list, node1);
// 	ft_lstadd_back(&list, node2);

// 	t_list *last_node = ft_lstlast(list);

//     if (last_node)
//         printf("The last node : %s\n", (char *)last_node->content);
//     else
//         printf("The list is empty.\n");
// 	ft_lstclear(&list, free);
//     return (0);
// }