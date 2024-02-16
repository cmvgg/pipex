/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvarela- <cvarela-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 12:23:01 by cvarela-          #+#    #+#             */
/*   Updated: 2023/09/22 22:17:32 by cvarela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void	*s, size_t	n)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = s;
	i = 0;
	while (i < n)
	{
		ptr[i] = 0;
		i++;
	}
}
/*
int main() {
    char cadena[10] = "vvvvvvvvv";
   size_t tamano = sizeof(cadena);



    ft_bzero(cadena, 8);

 write(1, cadena, 10);

	bzero(cadena, 8);


   write(1, cadena, 10);
 

    return 0;
}
*/