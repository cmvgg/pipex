/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvarela- <cvarela-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 12:23:08 by cvarela-          #+#    #+#             */
/*   Updated: 2023/09/21 12:23:09 by cvarela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t elements, size_t size)
{
	void	*s;

	s = malloc(elements * size);
	if (!(s))
		return (0);
	ft_bzero(s, size * elements);
	return (s);
}

/*
int main() {
    int *arreglo;
	int *arreglo2;
    int elementos = 5; 
	
    arreglo = (int *)calloc(elementos, sizeof(int));
	arreglo2 = (int *)ft_calloc(elementos, sizeof(int));

	   if (arreglo2 == NULL) {
        printf("Error: No se pudo asignar memoria. ft_\n");
    }

    if (arreglo == NULL) {
        printf("Error: No se pudo asignar memoria.\n");
        free(arreglo);
    	free(arreglo2);
		return 1; 
    }
	free(arreglo);
    free(arreglo2);

    printf("El programa ha terminado correctamente.\n");

    printf("El programa ha terminado correctamente. ft_\n");

    return 0;
}
*/