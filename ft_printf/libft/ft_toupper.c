/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvarela- <cvarela-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 12:25:54 by cvarela-          #+#    #+#             */
/*   Updated: 2023/09/22 22:36:49 by cvarela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
	{
		c -= 32;
	}
	return (c);
}

/*
int main() {
    char cadena[] = "esto es una cadena en minusculas";
	char cadena2[] = "esto es una cadena en minusculas";
    int longitud = strlen(cadena);
	 int longitud2 = strlen(cadena2);

	for (int i = 0; i < longitud; i++) {
        cadena[i] = ft_toupper(cadena[i]);
    }

    printf("Cadena modificada: %s\n", cadena);

    for (int i = 0; i < longitud2; i++) {
        cadena2[i] = toupper(cadena2[i]);
    }

    printf("Cadena modificada: %s\n", cadena2);

    return 0;
}
*/