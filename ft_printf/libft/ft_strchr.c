/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvarela- <cvarela-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 12:24:56 by cvarela-          #+#    #+#             */
/*   Updated: 2023/09/22 22:31:29 by cvarela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char) c)
			return ((char *)s);
		s++;
	}
	if (*s == (char) c)
		return ((char *)s);
	return (NULL);
}

/*
int main() {
    char cadena[] = "teste";
    char caracter = "";
    char *resultado;
	char *resultado2;

    resultado = ft_strchr(cadena, caracter);
	resultado2 = strchr(cadena, caracter);

	if (resultado != NULL) {
        printf("El carácter '%c' \
        se encuentra en la posición %ld de la cadena. ft_ \n", 
        caracter, resultado - cadena);
    } else {
        printf("El carácter '%c' \
        no se encuentra en la cadena. ft_\n", caracter);
    }if (resultado2 != NULL) {
        printf("El carácter '%c' \
        se encuentra en la posición %ld de la cadena.\n", 
        caracter, resultado2 - cadena);
    } else {
        printf("El carácter '%c' \
        no se encuentra en la cadena.\n", 
        caracter);
    }

    return 0;
}
*/