/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nunograzina <nunograzina@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 12:49:54 by nhorta-g          #+#    #+#             */
/*   Updated: 2022/08/10 12:08:18 by nunograzina      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./pipex.h"

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
			free(path);
		i++;
	}
	free(cmd_final);
	free_matrix(path_temp);
	return (0);
}
