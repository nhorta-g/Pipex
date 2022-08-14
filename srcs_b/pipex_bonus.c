/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhorta-g <nhorta-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 17:54:31 by nunograzina       #+#    #+#             */
/*   Updated: 2022/08/14 12:42:00 by nhorta-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	child_here_doc(int *pipe_fd, char *limiter)
{
	char	*line;

	line = NULL;
	close(pipe_fd[0]);
	while (ft_strncmp(limiter, line, ft_strlen(limiter)))
	{
		if (line)
			free(line);
		write(1, "> ", 2);
		line = get_next_line(STDIN_FILENO);
		write(pipe_fd[1], line, ft_strlen(line));
	}
	free(line);
	close(pipe_fd[1]);
	exit(EXIT_SUCCESS);
}

void	here_doc(int argc, char *limiter)
{
	int		pipe_fd[2];
	pid_t	pid;

	if (argc < 6)
		end_and_error_message("With here_doc minimum number of arguments is 6");
	if (pipe (pipe_fd) == -1)
		end_and_error_message("error creating pipe for here_doc");
	pid = fork();
	if (pid < 0)
		end_and_error_message("error forking for here_doc");
	if (pid == 0)
		child_here_doc(pipe_fd, limiter);
	else
	{
		close (pipe_fd[1]);
		dup2(pipe_fd[0], STDIN_FILENO);
		close (pipe_fd[0]);
		waitpid(pid, NULL, 0);
	}
}

void	execute_pipe_infinite_commands(char *argv, char **envp)
{
	pid_t	pid;
	int		pipe_fd[2];

	if (pipe(pipe_fd) < 0)
		end_and_error_message("Error creating pipe for bonus");
	pid = fork();
	if (pid < 0)
		end_and_error_message("Error forking for bonus");
	if (pid == 0)
	{
		close(pipe_fd[0]);
		dup2(pipe_fd[1], STDOUT_FILENO);
		execute(argv, envp);
	}
	else
	{
		close(pipe_fd[1]);
		dup2(pipe_fd[0], STDIN_FILENO);
		close(pipe_fd[0]);
		wait(NULL);
	}
}

int	main(int argc, char **argv, char**envp)
{
	int	i;
	int	file_fd[2];

	if (argc >= 5)
	{
		if (ft_strncmp(argv[1], "here_doc", 8) == 0)
		{
			i = 2;
			file_fd[1] = open_file(argv[argc - 1], 0);
			here_doc(argc, argv[2]);
		}
		else
		{
			i = 1;
			file_fd[0] = open_file(argv[1], 1);
			file_fd[1] = open_file(argv[argc - 1], 2);
			dup2(file_fd[0], STDIN_FILENO);
		}
		while (i < argc - 3)
			execute_pipe_infinite_commands(argv[++i], envp);
		dup2(file_fd[1], STDOUT_FILENO);
		execute(argv[argc - 2], envp);
	}
	else
		end_and_error_message("Not enough arguments, should be 5 or more");
}
