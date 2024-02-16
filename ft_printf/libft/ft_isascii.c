/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvarela- <cvarela-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 12:23:22 by cvarela-          #+#    #+#             */
/*   Updated: 2023/09/22 22:19:12 by cvarela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
	{
		return (1);
	}
	return (0);
}

/*
int main() {
    int valor = 65;

	if (ft_isascii(valor)) {
        printf("ft_ %d está dentro del rango ASCII válido.\n", valor);
    } else {
        printf("ft_ %d no está dentro del rango ASCII válido.\n", valor);
    }

    if (isascii(valor)) {
        printf("%d está dentro del rango ASCII válido.\n", valor);
    } else {
        printf("%d no está dentro del rango ASCII válido.\n", valor);
    }

    return 0;
}
*/