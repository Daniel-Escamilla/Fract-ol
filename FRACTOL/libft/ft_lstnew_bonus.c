/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: descamil <descamil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 10:57:35 by descamil          #+#    #+#             */
/*   Updated: 2023/11/21 18:33:35 by descamil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (new_node == NULL)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}
/*
int main()
{
    char *data = "Hello, World!";
    t_list *new_node = ft_lstnew(data);
    if (new_node) {
        printf("New node: %s\n", (char *)new_node->content);
        free(new_node);
    } else {
        printf("Failed to create a new node.\n");
    }
    return 0;
}
*/