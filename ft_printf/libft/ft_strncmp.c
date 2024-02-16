/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvarela- <cvarela-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 12:25:29 by cvarela-          #+#    #+#             */
/*   Updated: 2023/09/22 22:35:33 by cvarela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*tmp1;
	unsigned char	*tmp2;

	tmp1 = (unsigned char *)s1;
	tmp2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (--n && *tmp1 == *tmp2 && *tmp1 && *tmp2)
	{
		tmp1++;
		tmp2++;
	}
	return (*tmp1 - *tmp2);
}

/*
int main() {
    char str1[] = "Hola, mundo!";
    char str2[] = "Holaa, amigos!";
    int n = 6;

    int result = strncmp(str1, str2, n);
	int result2 = ft_strncmp(str1, str2, n);


    if (result == 0) {
        printf("Las primeras %d caracteres de las cadenas 
        son iguales.\n", n);
    } else if (result < 0) {
        printf("Las primeras %d caracteres de la cadena 1 
        son menores que los de la cadena 2.\n", n);
    } else {
        printf("Las primeras %d caracteres de la cadena 1 
        son mayores que los de la cadena 2.\n", n);
    }

if (result2 == 0) {
        printf("Las primeras %d caracteres de las cadenas 
        son iguales. ft_\n", n);
    } else if (result2 < 0) {
        printf("Las primeras %d caracteres de la cadena 
        1 son menores que los de la cadena 2. ft_\n", n);
    } else {
        printf("Las primeras %d caracteres de la cadena 
        1 son mayores que los de la cadena 2. ft_\n", n);
    }
    return 0;
}
*/