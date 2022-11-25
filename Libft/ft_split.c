/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engo <engo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 15:00:57 by engo              #+#    #+#             */
/*   Updated: 2021/06/06 16:30:34 by engo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_free(char **str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

size_t	ft_word(char const *str, char c)
{
	size_t	word;
	size_t	state;

	state = 1;
	word = 0;
	while (*str)
	{
		if (*str == c)
			state = 1;
		else
		{
			if (state == 1)
				word++;
			state = 0;
		}
		str++;
	}
	return (word);
}

size_t	word_lenght(char const *str, char c)
{
	size_t	i;

	i = 0;
	while (*str && *str != c)
	{
		i++;
		str++;
	}
	return (i);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	char	**dest;

	i = 0;
	if (s == 0)
		return (NULL);
	dest = (char **)malloc(sizeof(char *) * (ft_word(s, c) + 1));
	if (!dest)
		return (NULL);
	while (ft_word(s, c))
	{
		while (*s && *s == c)
			s++;
		dest[i] = (char *)malloc(sizeof(char) * (word_lenght(s, c) + 1));
		if (!dest[i])
			return (ft_free(dest));
		j = 0;
		while (*s != c && *s)
			dest[i][j++] = *s++;
		dest[i][j] = 0;
		i++;
	}
	dest[i] = 0;
	return (dest);
}
