/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvarela- <cvarela-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 12:24:24 by cvarela-          #+#    #+#             */
/*   Updated: 2023/10/05 15:39:14 by cvarela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dst_cp;
	unsigned char	*src_cp;

	if (dst == NULL && src == NULL)
		return (NULL);
	dst_cp = (unsigned char *)dst;
	src_cp = (unsigned char *)src;
	if (dst_cp > src_cp)
	{
		while (len--)
			dst_cp[len] = src_cp[len];
	}
	else
	{
		ft_memcpy(dst, src, len);
	}
	return (dst);
}
/*int main() {
    char source[32];
    //char source2[32];
	char source2[32] = "Hello, World!123555";
	strcpy(source, "Hello, World!12355454464891444");
	strcpy(source2, "Hello, World!12355454464891444");
    char dest1[40];
    char dest2[40];
	char dest3[40];
    char dest4[40];
	 

    // Using ft_memcpy
    ft_memcpy(dest1, source, strlen(source) + 1);
    printf("Using ft_memcpy: %s\n", dest1);

    // Using ft_memmove
    ft_memmove(dest2, source2, strlen(source2) + 1);
    printf("Using ft_memmove: %s\n", dest2);

    // Using memcpy from standard library
    memcpy(dest4, source2, strlen(source) + 1);
    printf("Using memcpy: %s\n", dest4);

    // Using memmove from standard library
    memmove(dest3, source2, strlen(source) + 1);
    printf("Using memmove: %s\n", dest3);

    return 0;
}
*/