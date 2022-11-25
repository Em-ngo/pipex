/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engo <engo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 14:23:02 by engo              #+#    #+#             */
/*   Updated: 2021/06/06 14:23:08 by engo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	c_tmp;

	i = 0;
	c_tmp = (const char)c;
	while (s[i])
	{
		if (s[i] == c_tmp)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == c_tmp)
		return ((char *)&s[i]);
	return (NULL);
}
