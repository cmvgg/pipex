/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvarela- <cvarela-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 12:23:30 by cvarela-          #+#    #+#             */
/*   Updated: 2023/09/22 22:19:21 by cvarela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c < 32 || c > 126)
	{
		return (0);
	}
	return (1);
}

/*
int main() {
  char c = 127;
  int is_print_ft;
  int is_print_std;

  is_print_ft = ft_isprint(c);
  is_print_std = isprint(c);

  if (is_print_ft) {
    printf("El carácter '%c' es imprimible (ft_isprint).\n", c);
  } else {
    printf("El carácter '%c' no es imprimible (ft_isprint).\n", c);
  }

  if (is_print_std) {
    printf("El carácter '%c' es imprimible (isprint).\n", c);
  } else {
    printf("El carácter '%c' no es imprimible (isprint).\n", c);
  }

  return 0;
}
*/