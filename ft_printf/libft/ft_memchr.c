/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvarela- <cvarela-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 17:31:29 by cvarela-          #+#    #+#             */
/*   Updated: 2023/09/22 22:24:31 by cvarela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*ptr;

	ptr = (const unsigned char *)s;
	while (n-- > 0)
	{
		if (*ptr == (unsigned char)c)
			return ((void *)ptr);
		ptr++;
	}
	return (0);
}

/*
nt main() {
    char str[] = "Hello, world!";
    char search_char = 'o';
    size_t str_len = strlen(str);

    void *result = ft_memchr(str, search_char, str_len);

    if (result != NULL) {
        printf("'%c' found at position: %ld\n",
						search_char, (char *)result - str);
    } else {
        printf("'%c' not found in the string.\n", search_char);
    }

    return 0;
}
*/