/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhorta-g <nhorta-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 12:49:04 by nhorta-g          #+#    #+#             */
/*   Updated: 2022/08/14 12:44:41 by nhorta-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <time.h>
# include "../libft/libft.h"
# include "../includes/get_next_line.h"

void	free_matrix(char **matrix);
int		end_and_error_message(char *msg);
void	execute(char *argv_cmd, char **envp);
int		open_file(char *argv, int option);
char	*get_next_line(int fd);

#endif
