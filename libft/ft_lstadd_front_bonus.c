/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: descamil <descamil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 12:37:25 by descamil          #+#    #+#             */
/*   Updated: 2023/11/21 18:34:04 by descamil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}
/*
int main()
{
	t_list *myList;
	t_list *newNode;

	myList = NULL;
	newNode = ft_lstnew("Contenido");
	ft_lstadd_front(&myList, newNode);
	return (0);
}
*/
