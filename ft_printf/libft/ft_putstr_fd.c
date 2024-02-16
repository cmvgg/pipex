/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvarela- <cvarela-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 12:24:43 by cvarela-          #+#    #+#             */
/*   Updated: 2023/09/22 22:30:07 by cvarela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	while (*s)
		ft_putchar_fd (*s++, fd);
}

/*
int main() {
    char *message = "Hello, world!";
    int file_descriptor = 1; // File descriptor for standard output (stdout)

    ft_putstr_fd(message, file_descriptor); // Print the message

    return 0;
}
*/