/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvarela- <cvarela-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 12:25:12 by cvarela-          #+#    #+#             */
/*   Updated: 2023/10/05 20:45:01 by cvarela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strlcat(char *dest, char *src, size_t size)
{
	unsigned int	dest_len;
	unsigned int	src_len;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	if (size <= dest_len)
		return (src_len + size);
	size -= dest_len;
	dest += dest_len;
	while (*src && size > 1)
	{
		*dest = *src;
		dest++;
		src++;
		size--;
	}
	*dest = '\0';
	return (dest_len + src_len);
}

/*
#include <string.h>
#include <stdio.h>
int main() {
    //char destino[20] = "hola";
    char *fuente = NULL;
	char destino2 = "1234";

    //size_t tamano_destino = sizeof(destino);
    size_t tamano_fuente = sizeof(fuente);
	size_t tamano_destino2 = sizeof(destino2);

  // size_t resultado = ft_strlcat(destino, fuente, 25);
	size_t resultado2 = strlcat(destino2, fuente, 25);

    //printf("Cadena concatenada: %s ft_\n", destino);
   // printf("Tamaño total después de concatenar: %zu ft_\n", resultado);

    printf("Cadena concatenada: %s\n", destino2);
    printf("Tamaño total después de concatenar: %zu\n", resultado2);

    return 0;
}*/
