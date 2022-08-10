/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nunograzina <nunograzina@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 12:49:04 by nhorta-g          #+#    #+#             */
/*   Updated: 2022/08/10 10:55:43 by nunograzina      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <time.h>
# include "./libft/libft.h"

char	*get_path(char **envp, char **cmds);
int		end_and_error_message(char *msg);
void	ft_close_parent_pipes(int *pipe_fd);
void	free_matrix(char **matrix);
void	execute(char *argv_cmd, char **envp);

#endif
