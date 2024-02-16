/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvarela- <cvarela-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 17:02:50 by cvarela-          #+#    #+#             */
/*   Updated: 2023/09/21 19:42:20 by cvarela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*pos;

	while (*lst)
	{
		pos = (*lst)->next;
		del((*lst)->content);
		free (*lst);
		*lst = pos;
	}
	pos = 0;
}
