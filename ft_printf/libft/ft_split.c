/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvarela- <cvarela-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 12:21:58 by cvarela-          #+#    #+#             */
/*   Updated: 2023/09/23 02:23:40 by cvarela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_splits(const char *s, char c, int *tab)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (*s)
	{
		if (*s != c)
			count++;
		if ((*s == c && count) || (!*(s + 1) && count))
		{
			tab[i++] = count;
			count = 0;
		}
		s++;
	}
	return (i);
}

static void	ft_strscpy(char **split, const char *s, char c)
{
	int	i;
	int	si;

	i = 0;
	si = 0;
	while (*s)
	{
		if (*s != c)
			split[si][i++] = *s;
		else if (*s == c && i)
		{
			si++;
			i = 0;
		}
		s++;
	}
}

static char	**ft_free(char **split, int *tab, int i)
{
	int	n;

	n = 0;
	while (n < i)
		free(split[n++]);
	free(split);
	free(tab);
	return (NULL);
}

char	**ft_split(const char *s, char c)
{
	int		i;
	int		*tab;
	int		words;
	char	**split;

	if (!s)
		return (NULL);
	tab = ft_calloc((ft_strlen(s) / 2 + 5), sizeof(int));
	if (!tab)
		return (NULL);
	words = ft_count_splits(s, c, tab);
	split = ft_calloc((words + 1), sizeof(char *));
	if (!(split))
		return (free(tab), NULL);
	i = 0;
	while (i < words)
	{
		split[i] = ft_calloc(tab[i] + 1, sizeof(char));
		if (!(split[i]))
			return (ft_free(split, tab, i), NULL);
		i++;
	}
	free(tab);
	ft_strscpy(split, s, c);
	return (split);
}

/*
int main() {
    const char *str = "This,is,a,test";
    char **result = ft_split(str, ',');
    if (result != NULL) {
        int i = 0;
        while (result[i] != NULL) {
            printf("Split %d: %s\n", i, result[i]);
            free(result[i]);
            i++;
        }
        free(result);
    } else {
        printf("Memory allocation failed.\n");
    }
    return 0;
}
*/