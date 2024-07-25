/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srodrigo <srodrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 12:28:20 by srodrigo          #+#    #+#             */
/*   Updated: 2024/07/25 21:14:04 by algarrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"
#include "mstypes.h"
#include <unistd.h>
#include "token.h"
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

/* NOTE: ft_putend_fl is giving linking problems!!!
   so I had to print \n (so far)
   TODO That exit should be a return in case the redirection is for
   a builtin executed by the parent, otherwise would exit minishell!!!
*/
int	infile_redirection(t_token *token)
{
	int			fd;
	const char	*file;

	file = get_value(token);
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Error: ", 2);
		ft_putstr_fd(strerror(errno), 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd((char *) file, 2);
		ft_putchar_fd('\n', 2);
		return (errno);
	}
	dup2(fd, STDIN_FILENO);
	close(fd);
	return (0);
}

int	outfile_redirection(t_token *token)
{
	int			fd;
	const char	*file;

	file = get_value(token);
	fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (fd == -1)
	{
		printf("Error: %s: %s\n", strerror(errno), file);
		return (EXIT_FAILURE);
	}
	dup2(fd, STDOUT_FILENO);
	close(fd);
	return (0);
}

int	outfile_appended_redirection(t_token *token)
{
	int			fd;
	const char	*file;

	file = get_value(token);
	fd = open(file, O_WRONLY | O_CREAT | O_APPEND, 0666);
	if (fd == -1)
	{
		printf("Error: %s: %s\n", strerror(errno), file);
		return (EXIT_FAILURE);
	}
	dup2(fd, STDOUT_FILENO);
	close(fd);
	return (0);
}

int	heredoc_redirection(t_token *token)
{
	int			hdpipe[2];
	const char	*hdvalue;

	hdvalue = get_value(token);
	if (pipe(hdpipe) == -1)
	{
		printf("Error: %s: Heredoc\n", strerror(errno));
		return (EXIT_FAILURE);
	}
	write(hdpipe[WRITE_END], hdvalue, ft_strlen(hdvalue));
	close(hdpipe[WRITE_END]);
	dup2(hdpipe[READ_END], STDIN_FILENO);
	close(hdpipe[READ_END]);
	return (0);
}

void	expand_command(t_token *token, t_dlist *environ)
{
	set_type(token, TKN_CMD);
	set_value(token, get_name_value(get_value(token), environ));
}
