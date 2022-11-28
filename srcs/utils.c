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

void	ft_free_pipex(char **str)
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

void	ft_execve(char **exec, char *cmd, char **envp)
{
	if (execve(cmd, exec, envp) == -1)
	{
		perror("Error, command not found.\n");
		ft_putstr_fd(exec[0], 2);
		ft_free_pipex(exec);
		exit(EXIT_FAILURE);
	}
	else
		return;
}

void	check_exec(char **exec, char **list_path)
{
	if (exec[0] == NULL)
	{
		perror("Command not found.\n");
		ft_free_pipex(list_path);
		ft_free_pipex(exec);
		exit(EXIT_FAILURE);
	}
}
