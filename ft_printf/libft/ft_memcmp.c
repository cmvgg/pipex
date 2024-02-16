/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvarela- <cvarela-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 17:31:32 by cvarela-          #+#    #+#             */
/*   Updated: 2023/09/23 01:35:36 by cvarela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*s1u;
	const unsigned char	*s2u;

	s1u = (const unsigned char *)s1;
	s2u = (const unsigned char *)s2;
	while (n-- > 0)
	{
		if (*s1u != *s2u)
			return (*s1u - *s2u);
		s1u++;
		s2u++;
	}
	return (0);
}

/*
int main() {
    char str1[] = "Hello, world!";
    char str2[] = "Hello, there!";
    size_t compare_length = 5;  

    int result = ft_memcmp(str1, str2, compare_length);

    if (result == 0) {
        printf("The first %zu characters are identical.\n", compare_length);
    } else if (result < 0) {
        printf("The character in str1 is less than that in str2.\n");
    } else {
        printf("The character in str1 is greater than that in str2.\n");
    }

    return 0;
}
*/