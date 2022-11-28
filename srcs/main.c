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

char	*find_cmd(char *path_cmd, char **exec)
{
	int		i;
	char	**list_path;
	char	*good_path;
	char	*full_path;
	char	*tmp;

	i = 0;
	list_path = ft_split(path_cmd, ':');
	check_exec(exec, list_path);
	if (access(exec[0], F_OK) == 0)
		return (exec[0]);
	while (list_path[i])
	{
		good_path = ft_strjoin(list_path[i], "/");
		tmp = ft_strdup(good_path);
		full_path = ft_strjoin(tmp, exec[0]);
		free(good_path);
		free(tmp);
		if (access(full_path, F_OK) == 0)
			return (full_path);
		free(full_path);
		i++;
	}
	ft_free(list_path);
	return ("<");
}

void	ft_parent(int *pipe, char **av, char **envp)
{
	int		fd;
	char	**exec;
	char	*cmd;
	char	*path;

	fd = open(av[4], O_CREAT | O_WRONLY | O_TRUNC, 0666); 
	if (fd < 0)
	{
		perror("An error has occured.\n");
		exit(EXIT_FAILURE);
	}
	path = ft_path_cmd(envp);
	exec = ft_split(av[3], ' ');
	cmd = find_cmd(path, exec);
	dup2(pipe[0], 0);
	dup2(fd, 1);
	close(pipe[1]);
}

void	ft_child(int *pipe, char **av, char **envp)
{
	int		fd;
	char	**exec;
	char	*cmd;
	char	*path;

	fd = open(av[1], O_RDONLY);
	if (fd < 0)
	{
		perror("An error has occured.\n");
		exit(EXIT_FAILURE);
	}
	path = ft_path_cmd(envp);
	exec = ft_split(av[2], ' ');
	cmd = find_cmd(path, exec);
	dup2(pipe[1], 1);
	dup2(fd, 0);
	close(pipe[0]);
}

int	main(int ac, char **av, char **envp)
{
	pid_t	id;
	int		fd[2];

	if (ac > 5)
		error_exit("Error, too many arguments.\n");
	if (ac < 5)
		error_exit("Error, missing arguments.\n");
	if (ac == 5)
	{
		if (pipe(fd) == -1)
			error_exit("Error, pipe failed.\n");
		id = fork();
		if (id == -1)
			error_exit("Error, fork failed.\n");
		if (id == 0)
			ft_child(id, av, envp);
		ft_parent(id, av, envp);
	}
	return (0);
}
