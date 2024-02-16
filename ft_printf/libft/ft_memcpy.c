/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvarela- <cvarela-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 12:24:20 by cvarela-          #+#    #+#             */
/*   Updated: 2023/09/21 12:24:21 by cvarela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (dst == NULL && src == NULL)
		return (NULL);
	i = -1;
	while (++i < n)
		*((char *)dst + i) = *((char *)src + i);
	return (dst);
}

/*
int main() {
    char source[32];
    char source2[32];
	strcpy(source, "Hello, World!12355454464891444");
	strcpy(source2, "Hello, World!12355454464891444");
    char dest1[40];
    char dest4[40];
	 
    ft_memcpy(dest1, source, strlen(source) + 1);
    printf("%s Using ft_memcpy\n", dest1);


    memcpy(dest4, source2, strlen(source) + 1);
    printf("%s Using memcpy\n", dest4);

    return 0;
}
*/