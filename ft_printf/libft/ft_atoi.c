/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvarela- <cvarela-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 12:22:53 by cvarela-          #+#    #+#             */
/*   Updated: 2023/09/22 22:12:44 by cvarela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	parse_digits(const char **str)
{
	unsigned int	nb;

	nb = 0;
	while (**str >= '0' && **str <= '9')
	{
		nb = (nb * 10) + (**str - '0');
		(*str)++;
	}
	return (nb);
}

int	ft_atoi(const char *str)
{
	unsigned int	nb;
	short int		sign;

	sign = 1;
	nb = 0;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	nb = parse_digits(&str);
	if (nb > 2147483647 && sign == 1)
		return (-1);
	else if (nb - 1 > 2147483647 && sign == -1)
		return (0);
	return ((int)(nb * sign));
}

/*
int main() {
  char *str = "----+1234.5";
  int n;

	n = ft_atoi(str);

  
  printf("El número convertido es %d\n", n);

  n = atoi(str);

  printf("El número convertido es %d\n", n);

  return 0;
}
*/
