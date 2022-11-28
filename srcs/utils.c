/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engo <engo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 12:37:28 by engo              #+#    #+#             */
/*   Updated: 2022/11/25 12:54:36 by engo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_exit(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}

void	ft_free(char **str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		str[i] = NULL;
		i++;
	}
	free(str);
	*str = NULL;
}

void	check_exec(char **exec, char **list_path)
{
	if (exec[0] == NULL)
	{
		perror("Command not found.\n");
		ft_free(list_path);
		ft_free(exec);
		exit(EXIT_FAILURE);
	}
}

void	