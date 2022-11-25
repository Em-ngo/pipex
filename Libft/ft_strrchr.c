/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engo <engo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 14:24:30 by engo              #+#    #+#             */
/*   Updated: 2021/06/06 14:24:39 by engo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	c_tmp;
	int		len;

	len = ft_strlen(s);
	c_tmp = (const char)c;
	while (len)
	{
		if (s[len] == c_tmp)
			return ((char *)&s[len]);
		len--;
	}
	if (s[0] == c_tmp)
		return ((char *)&s[len]);
	return (NULL);
}
