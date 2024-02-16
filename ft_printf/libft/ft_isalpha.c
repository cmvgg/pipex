/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvarela- <cvarela-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 12:23:18 by cvarela-          #+#    #+#             */
/*   Updated: 2023/09/22 22:19:07 by cvarela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

/*
int main() {
  char c = '3';
  int is_alpha_ft;
  int is_alpha_std;

  is_alpha_ft = ft_isalpha(c);
  is_alpha_std = isalpha(c);

  if (is_alpha_ft) {
    printf("El carácter '%c' es alfabético (ft_isalpha).\n", c);
  } else {
    printf("El carácter '%c' no es alfabético (ft_isalpha).\n", c);
  }

  if (is_alpha_std) {
    printf("El carácter '%c' es alfabético (isalpha).\n", c);
  } else {
    printf("El carácter '%c' no es alfabético (isalpha).\n", c);
  }

  return 0;
}
*/