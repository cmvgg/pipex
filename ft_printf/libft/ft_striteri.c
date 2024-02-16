/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvarela- <cvarela-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 12:25:03 by cvarela-          #+#    #+#             */
/*   Updated: 2023/09/22 22:33:28 by cvarela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	if (s == NULL || *s == '\0')
	{
		return ;
	}
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

/*
void example_striteri(unsigned int index, char *c) {
    printf("Character at index %u: %c\n", index, *c);
}

int main() {
    char str[] = "Hello, world!";
    
    printf("Original string: %s\n", str);

    ft_striteri(str, example_striteri);

    return 0;
}
*/