/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvarela- <cvarela-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 12:24:28 by cvarela-          #+#    #+#             */
/*   Updated: 2023/09/21 12:24:29 by cvarela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (n--)
	{
		*ptr++ = (unsigned char)c;
	}
	return (s);
}
/*
#include <stdio.h>
#include <string.h>

int main() {

    char str[5];
	char str2[5];


    memset(str2, '1', sizeof(str2));

    printf("%s\n", str2);

	ft_memset(str, '1', sizeof(str));

    printf("%s\n", str);

    return 0;
}
*/