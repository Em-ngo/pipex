/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engo <engo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 12:36:14 by engo              #+#    #+#             */
/*   Updated: 2022/11/25 13:17:06 by engo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_path_cmd(char **path)
{
	int	i;

	i = 0;
	while (path[i] && ft_strncmp(path[i], "PATH=", 5))
		i++;
	return (i);
}

void	child(int pipe, char **av, char **envp)
{
	int		*fd;
	char	*cmd;
	char	*path;
	char	**exect;

	fd = open(av[1], O_RDONLY);
	if (fd < 0)
	{
		perror("An error has occured.\n");
		exit(EXIT_FAILURE);
	}
	path = ft_path_cmd(envp);

}


int	main(int ac, char **av, char **envp)
{
	pid_t	id;
	int		fd[2];

	if (ac > 5)
		perror("Error, too many arguments.\n");
	if (ac < 5)
		perror("Error, missing arguments.\n");
	if (ac == 5)
	{
		if (pipe(fd) == -1)
		{
			perror("An error has occured.\n");
			exit(EXIT_FAILURE);
		}
		id = fork();
		if (id == -1)
		{
			perror("An error has occured.\n");
			exit(EXIT_FAILURE);
		}
		if (id == 0)
			ft_child(id, av, envp);
		ft_parent(id, av, envp);
	}
	return (0);
}
