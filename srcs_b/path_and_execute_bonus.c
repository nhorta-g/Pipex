/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_and_execute_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhorta-g <nhorta-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 12:43:02 by nhorta-g          #+#    #+#             */
/*   Updated: 2022/08/14 12:45:02 by nhorta-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

static char	*extract_path_line(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (!ft_strncmp(envp[i], "PATH=", 5))
			return (envp[i]);
		i++;
	}
	return (0);
}

char	*get_path(char **envp, char **cmds)
{
	int		i;
	char	*cmd_final;
	char	*path;
	char	**path_temp;

	i = 0;
	cmd_final = ft_strjoin("/", cmds[0]);
	path_temp = ft_split(ft_strchr(extract_path_line(envp), '/'), ':');
	while (path_temp[i])
	{
		path = ft_strjoin(path_temp[i], cmd_final);
		if (access(path, F_OK) == 0)
		{
			free(cmd_final);
			free_matrix(path_temp);
			return (path);
		}
		else
			free(path);
		i++;
	}
	free(cmd_final);
	free_matrix(path_temp);
	return (0);
}

void	execute(char *argv_cmd, char **envp)
{
	char	*path;
	char	**cmds;

	cmds = ft_split(argv_cmd, ' ');
	path = get_path(envp, cmds);
	if (execve(path, cmds, envp) < 0)
	{
		free_matrix(cmds);
		free(path);
		end_and_error_message("Error executing command");
	}
}
