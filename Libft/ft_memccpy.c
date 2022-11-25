/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engo <engo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 14:20:18 by engo              #+#    #+#             */
/*   Updated: 2021/06/06 14:20:19 by engo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t					i;
	unsigned char			c_tmp;
	unsigned char			*d_tmp;
	unsigned char			*s_tmp;

	c_tmp = (unsigned char)c;
	d_tmp = (unsigned char *)dst;
	s_tmp = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		d_tmp[i] = s_tmp[i];
		if (s_tmp[i] == c_tmp)
			return (d_tmp + i + 1);
		i++;
	}
	return (NULL);
}
