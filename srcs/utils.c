/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhorta-g <nhorta-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 12:49:50 by nhorta-g          #+#    #+#             */
/*   Updated: 2022/08/14 12:29:06 by nhorta-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	end_and_error_message(char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}

void	free_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
		free(matrix[i++]);
	free(matrix);
}

void	ft_close_parent_pipes(int *pipe_fd)
{
	if (close(pipe_fd[0]) < 0)
		end_and_error_message("error closing read end pipe in parent process");
	if (close(pipe_fd[1]) < 0)
		end_and_error_message("error closing write end pipe in parent process");
}
