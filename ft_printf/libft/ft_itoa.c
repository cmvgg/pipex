/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvarela- <cvarela-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 12:23:34 by cvarela-          #+#    #+#             */
/*   Updated: 2023/10/02 12:27:20 by cvarela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_digits(int n)
{
	size_t	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static void	ft_fill_result(char *result, size_t len,
						unsigned int nbr, int neg)
{
	result[len] = '\0';
	while (len--)
	{
		result[len] = nbr % 10 + '0';
		nbr /= 10;
	}
	if (neg)
		result[0] = '-';
}

static char	*ft_less0(int n)
{
	char	*result;

	if (n == 0)
	{
		result = malloc(2 * sizeof(char));
		if (!result)
			return (NULL);
		result[0] = '0';
		result[1] = '\0';
		return (result);
	}
	return (NULL);
}

char	*ft_itoa(int n)
{
	size_t	len;
	int		neg;
	char	*result;

	if (n == 0)
		return (ft_less0(n));
	len = 0;
	neg = 0;
	if (n < 0)
	{
		neg = 1;
		n = -n;
		len++;
	}
	len += ft_count_digits(n);
	result = malloc(len + 1);
	if (!result)
		return (NULL);
	ft_fill_result(result, len, n, neg);
	return (result);
}

/*
int main() {
    int num = -12345; 
    char *result = ft_itoa(num); 
    if (result != NULL) {
        printf("Integer: %d\n", num);
        printf("String: %s\n", result);
        free(result);
    } else {
        printf("Memory allocation failed.\n");
    }
    return 0;
}
*/