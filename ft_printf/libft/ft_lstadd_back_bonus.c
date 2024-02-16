/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvarela- <cvarela-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 12:23:38 by cvarela-          #+#    #+#             */
/*   Updated: 2023/09/25 16:54:19 by cvarela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (*lst == 0)
		*lst = new;
	else
		ft_lstlast(*lst)->next = new;
}

/*int main() {
    t_list *node1 = ft_lstnew(10);
    t_list *node2 = ft_lstnew(20);
    t_list *node3 = ft_lstnew(30);

    t_list *list = node1;

    ft_lstadd_back(&list, node2);
    ft_lstadd_back(&list, node3);

    printf("List data: ");
    t_list *current = list;
    while (current) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");

    free(node1);
    free(node2);
    free(node3);

    return 0;
} */