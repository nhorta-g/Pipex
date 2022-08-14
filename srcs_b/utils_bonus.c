/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhorta-g <nhorta-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 18:12:56 by nunograzina       #+#    #+#             */
/*   Updated: 2022/08/14 12:45:50 by nhorta-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

int	end_and_error_message(char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}

int	open_file(char *argv, int option)
{
	int	fd;

	fd = 0;
	if (option == 0)
	{
		fd = open(argv, O_WRONLY | O_CREAT | O_APPEND, 0777);
		if (fd < 0)
			end_and_error_message
			("error oppening outfile for here_doc for bonus");
	}
	else if (option == 1)
	{
		fd = open(argv, O_RDONLY, 0777);
		if (fd < 0)
			end_and_error_message("error oppening infile for bonus");
	}
	else if (option == 2)
	{
		fd = open(argv, O_WRONLY | O_CREAT | O_TRUNC, 0777);
		if (fd < 0)
			end_and_error_message("error oppening outfile for bonus");
	}
	return (fd);
}

void	free_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
		free(matrix[i++]);
	free(matrix);
}
