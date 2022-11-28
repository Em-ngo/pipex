/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engo <engo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 10:48:59 by engo              #+#    #+#             */
/*   Updated: 2022/11/25 13:12:27 by engo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include "libft.h"
# include <sys/stat.h>
# include <fcntl.h>

void    check_exec(char **exec, char **list_path);
void    ft_free_pipex(char **str);
void    ft_execve(char **exec, char *cmd, char **evnp);
void    error_exit(char *str);

#endif