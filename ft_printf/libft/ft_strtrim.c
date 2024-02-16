/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvarela- <cvarela-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 12:25:40 by cvarela-          #+#    #+#             */
/*   Updated: 2023/10/02 12:29:19 by cvarela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s, char const *set)
{
	int		len;
	int		start;
	int		end;
	char	*str;

	if (!s || !set)
		return (NULL);
	len = ft_strlen(s);
	start = 0;
	end = len - 1;
	while (s[start] && ft_strchr(set, s[start]))
		start++;
	while (end > start && ft_strchr(set, s[end]))
		end--;
	str = ft_substr(s, start, end - start + 1);
	return (str);
}

/*
int main() {
    const char str[] = "comproba dos";
    const char set[] = "NULL";
       char *result = ft_strtrim(str, set);
	   
    printf("Original string: %s\n", str);
    printf("Set of characters to trim: %s\n", set);

 

    if (result != NULL) {
        printf("Trimmed string: %s\n", result);
        free(result);
    } else {
        printf("Memory allocation failed.\n");
    }

    return 0;
}*/