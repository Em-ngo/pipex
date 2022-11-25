/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engo <engo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 14:19:31 by engo              #+#    #+#             */
/*   Updated: 2021/06/06 14:19:33 by engo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*new;
	t_list	*lst_tmp;

	lst_tmp = *lst;
	while (lst_tmp)
	{
		new = lst_tmp;
		lst_tmp = lst_tmp->next;
		del(new->content);
		free(new);
	}
	*lst = NULL;
}
