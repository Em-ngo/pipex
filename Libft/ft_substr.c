/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engo <engo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 14:24:44 by engo              #+#    #+#             */
/*   Updated: 2021/06/06 15:48:35 by engo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{	
	char	*str;
	size_t	i;
	size_t	j;

	i = -1;
	if (!s)
		return (NULL);
	j = ft_strlen(s);
	if (!len || j <= start)
		return (ft_strdup(""));
	if (j < len)
		len = j;
	str = (char *)malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	j = 0;
	while (s[++i] && j < len)
	{
		if (i >= start)
			str[j++] = s[i];
	}
	str[j] = '\0';
	return (str);
}
