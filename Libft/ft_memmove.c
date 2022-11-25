/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engo <engo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 14:20:46 by engo              #+#    #+#             */
/*   Updated: 2021/06/06 14:20:47 by engo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	boucle(char *src, char *dst, int i, int len)
{
	while (i < len)
	{
		dst[i] = src[i];
		i++;
	}
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*dst_tmp;
	char	*src_tmp;
	int		len_tmp;

	len_tmp = (int)len - 1;
	dst_tmp = (char *)dst;
	src_tmp = (char *)src;
	i = 0;
	if (dst == NULL && src == NULL)
		return (NULL);
	if (src_tmp < dst_tmp)
	{
		while (len_tmp >= 0)
		{
			dst_tmp[len_tmp] = src_tmp[len_tmp];
			len_tmp--;
		}
	}
	else
		boucle(src_tmp, dst_tmp, i, len);
	return (dst);
}
