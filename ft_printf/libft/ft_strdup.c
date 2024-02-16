/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvarela- <cvarela-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 12:24:59 by cvarela-          #+#    #+#             */
/*   Updated: 2023/09/22 22:31:37 by cvarela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	size_t	len;
	char	*copy;

	len = ft_strlen(str);
	copy = (char *)malloc(len + 1);
	if (str == NULL)
	{
		return (NULL);
	}
	if (copy != NULL)
	{
		ft_memcpy(copy, str, len);
		copy[len] = '\0';
	}
	return (copy);
}

/*
int main() {
    const char *cadena_original = "Hola, mundo!";
    char *cadena_duplicada;
	char *cadena_duplicada2;

    cadena_duplicada = strdup(cadena_original);
    cadena_duplicada2 = ft_strdup(cadena_original);

    if (cadena_duplicada == NULL) {
        printf("Error: No se pudo duplicar la cadena.\n");
        return 1;
    }

    printf("Cadena original: %s\n", cadena_original);
    printf("Cadena duplicada: %s\n", cadena_duplicada);

	if (cadena_duplicada2 == NULL) {
        printf("Error: No se pudo duplicar la cadena. ft_\n");
        return 1;
    }

    printf("Cadena duplicada: %s ft_\n", cadena_duplicada2);

    free(cadena_duplicada);
    free(cadena_duplicada2);

    return 0;
}
*/