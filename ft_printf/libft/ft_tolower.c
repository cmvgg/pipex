/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvarela- <cvarela-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 12:25:49 by cvarela-          #+#    #+#             */
/*   Updated: 2023/09/21 12:25:50 by cvarela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)

{
	if (c >= 'A' && c <= 'Z')
	{
		c += 32;
	}
	return (c);
}

/*
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char cadena[] = "ESTO ES UNA CADENA EN MAYUSCULAS";
	char cadena2[] = "ESTO ES UNA CADENA EN MAYUSCULAS";
    int longitud = strlen(cadena);
	 int longitud2 = strlen(cadena2);

	for (int i = 0; i < longitud; i++) {
        cadena[i] = ft_tolower(cadena[i]);
    }

    printf("Cadena modificada: %s\n", cadena);

    for (int i = 0; i < longitud2; i++) {
        cadena2[i] = tolower(cadena2[i]);
    }

    printf("Cadena modificada: %s\n", cadena2);

    return 0;
}
*/