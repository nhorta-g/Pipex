/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nunograzina <nunograzina@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 12:49:50 by nhorta-g          #+#    #+#             */
/*   Updated: 2022/08/10 11:36:45 by nunograzina      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./pipex.h"

int	end_and_error_message(char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}

void	ft_close_parent_pipes(int *pipe_fd)
{
	if (close(pipe_fd[0]) < 0)
		end_and_error_message("error closing read end pipe in parent process");
	if (close(pipe_fd[1]) < 0)
		end_and_error_message("error closing write end pipe in parent process");
}

void	free_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
		free(matrix[i++]);
	free(matrix);
}

void	execute(char *argv_cmd, char **envp)
{
char	*path;
char	**cmds;

cmds = ft_split(argv_cmd, ' ');
path = get_path(envp, cmds);
if (execve(path, cmds, envp) < 0)
	{
		free(path);
		free_matrix(cmds);
		end_and_error_message("Error executing command");
	}
}
