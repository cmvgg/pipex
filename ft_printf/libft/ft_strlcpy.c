/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvarela- <cvarela-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 12:25:16 by cvarela-          #+#    #+#             */
/*   Updated: 2023/09/21 12:25:17 by cvarela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	unsigned int	i;

	i = 0;
	while (src[i] && i + 1 < size)
	{
		dest[i] = src[i];
		i++;
	}
	if (size > 0)
	{
		dest[i] = '\0';
	}
	while (src[i])
	{
		i++;
	}
	return (i);
}

/*
int main() {
    char destino[20] = "lalal";
    char fuente[] = "tarara";
	char destino2[20];

	size_t tamano_destino = sizeof(destino);
    size_t tamano_destino2 = sizeof(destino2);

    size_t resultado = ft_strlcpy(destino, fuente, tamano_destino);
    size_t resultado2 = strlcpy(destino2, fuente, tamano_destino2);

    printf("Cadena copiada: %s ft_\n", destino);
    printf("Tamaño total después de copiar: %zu ft_\n", resultado);

    printf("Cadena copiada: %s st\n", destino2);
    printf("Tamaño total después de copiar: %zu st\n", resultado2);

    return 0;
}
*/