/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nunograzina <nunograzina@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 12:49:58 by nhorta-g          #+#    #+#             */
/*   Updated: 2022/08/10 12:12:49 by nunograzina      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./pipex.h"

//Child2 recebe output do child 1 através do read end do pipe
//e será seu input. Executa cmd e redireciona o output para outfile
static void	child2(int *pipe_fd, char **argv, char **envp)
{
	int	fd_outfile;

	close(pipe_fd[1]);
	dup2(pipe_fd[0], STDIN_FILENO);
	close(pipe_fd[0]);
	fd_outfile = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0777);
	if (fd_outfile < 0)
		end_and_error_message("Error creating outfile in child2");
	dup2(fd_outfile, STDOUT_FILENO);
	close(fd_outfile);
	execute(argv[3], envp);
}

//child1 lê do Infile, executa cmd1 e redireciona o output para
//write end do pipe que o child2 vai receber como input
static void	child1(int *pipe_fd, char **argv, char **envp)
{
	int	fd_infile;

	close(pipe_fd[0]);
	fd_infile = open(argv[1], O_RDONLY, 0777);
	if (fd_infile < 0)
		end_and_error_message("Error opening infile in child1");
	dup2(fd_infile, STDIN_FILENO);
	close(fd_infile);
	dup2(pipe_fd[1], STDOUT_FILENO);
	close(pipe_fd[1]);
	execute(argv[2], envp);
}

int	main(int argc, char **argv, char **envp)
{
	int		pipe_fd[2];
	pid_t	pid;

	if (argc != 5)
		end_and_error_message("Arguments quantity incorrect, must be 5");
	if (pipe(pipe_fd) < 0)
		end_and_error_message("Error creating pipe");
	pid = fork();
	if (pid < 0)
		end_and_error_message("Error first forking");
	if (pid == 0)
		child1(pipe_fd, argv, envp);
	else
	{
		wait(NULL);
		pid = fork();
		if (pid < 0)
			end_and_error_message("Error second forking");
		if (pid == 0)
			child2(pipe_fd, argv, envp);
		else
			ft_close_parent_pipes(pipe_fd);
	}
	wait(NULL);
	return (0);
}
