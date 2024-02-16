/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvarela- <cvarela-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 12:25:33 by cvarela-          #+#    #+#             */
/*   Updated: 2023/09/21 12:25:34 by cvarela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t max)
{
	size_t	find_len;
	size_t	n;

	n = 0;
	if (*to_find == '\0')
		return ((char *)str);
	find_len = ft_strlen(to_find);
	while (*str)
	{
		if (find_len + n > max)
			return (NULL);
		if (ft_strncmp(str, to_find, find_len) == 0)
			return ((char *)str);
		str++;
		n++;
	}
	return (NULL);
}

/*
int main()
{
    char source[] = "heprtchalrld! addddcccc";
    char target[] = "ep";
    int max = 100;

    char *result = ft_strnstr(source, target, max);

    if (result != NULL)
    {
        puts(result);
    }
    else
    {
        printf("ft_strnstr Subcadena no encontrada\n");
    }

    char *result2 = strnstr(source, target, max);

    if (result2 != NULL)
    {
        puts(result2);
    }
    else
    {
        printf("strnstr Subcadena no encontrada.\n");
    }

    return 0;
}
*/