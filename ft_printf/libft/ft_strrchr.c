/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvarela- <cvarela-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 12:25:36 by cvarela-          #+#    #+#             */
/*   Updated: 2023/09/22 22:35:41 by cvarela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		len;
	char	*tmp;

	tmp = (char *)s;
	len = ft_strlen(s);
	if (*(tmp + len) == (char)c)
		return (tmp + len);
	while (len > 0)
	{
		len--;
		if (*(tmp + len) == (char)c)
			return (tmp + len);
	}
	return (NULL);
}

/*
int main() {
  char *str = "Esto es una cadena.";
  char c = '.';

  char *pos = ft_strrchr (str, c);
  
  if (pos != NULL) {
    printf("El carácter '%c' se encuentra en la posición %d\n", c, pos - str);
  } else {
    printf("El carácter '%c' no se encuentra en la cadena\n", c);
  }
  
  char *pos2 = strrchr(str, c);

  if (pos2 != NULL) {
    printf("El carácter '%c' se encuentra en la posición %d\n", c, pos2 - str);
  } else {
    printf("El carácter '%c' no se encuentra en la cadena\n", c);
  }

  return 0;
}
*/