/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvarela- <cvarela-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 12:23:13 by cvarela-          #+#    #+#             */
/*   Updated: 2023/09/22 22:18:49 by cvarela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')
		|| (c >= '0' && c <= '9'))
	{
		return (1);
	}
	return (0);
}

/*
int main() {
    char caracter = '1';
	char caracter2 = '1';

		if (ft_isalnum(caracter)) {
        printf("%c es un carácter alfanumérico.\n", caracter);
    } else {
        printf("%c no es un carácter alfanumérico.\n", caracter);
    }

    if (isalnum(caracter)) {
        printf("%c es un carácter alfanumérico.\n", caracter);
    } else {
        printf("%c no es un carácter alfanumérico.\n", caracter);
    }
    


    return 0;
}
*/