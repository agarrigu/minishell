/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srodrigo <srodrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 12:28:20 by srodrigo          #+#    #+#             */
/*   Updated: 2024/07/02 14:42:17 by srodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"
#include "mstypes.h"
#include <unistd.h>
#include "token.h"
#include <stdlib.h>
#include <stdio.h>
#include "env_util.h"
#include "builtins.h"
#include <fcntl.h>
#include <errno.h>
#include <string.h>

void	infile_redirection(t_token *token)
{
	int			fd;
	const char	*file;

	file = get_value(token);
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		printf("Error: %s: %s\n", strerror(errno), file);
		exit (EXIT_FAILURE);
	}
	dup2(fd, STDIN_FILENO);
	close(fd);
}

void	outfile_redirection(t_token *token)
{
	int			fd;
	const char	*file;

	file = get_value(token);
	fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (fd == -1)
	{
		printf("Error: %s: %s\n", strerror(errno), file);
		exit (EXIT_FAILURE);
	}
	dup2(fd, STDOUT_FILENO);
	close(fd);
}

void	outfile_appended_redirection(t_token *token)
{
	int			fd;
	const char	*file;

	file = get_value(token);
	fd = open(file, O_WRONLY | O_CREAT | O_APPEND, 0666);
	if (fd == -1)
	{
		printf("Error: %s: %s\n", strerror(errno), file);
		exit (EXIT_FAILURE);
	}
	dup2(fd, STDOUT_FILENO);
	close(fd);
}

void	heredoc_redirection(t_token *token)
{
	int			hdpipe[2];
	const char	*hdvalue;

	hdvalue = get_value(token);
	if (pipe(hdpipe) == -1)
	{
		printf("Error: %s: Heredoc\n", strerror(errno));
		exit (EXIT_FAILURE);
	}
	write(hdpipe[WRITE_END], hdvalue, ft_strlen(hdvalue));
	close(hdpipe[WRITE_END]);
	dup2(hdpipe[READ_END], STDIN_FILENO);
	close(hdpipe[READ_END]);
}

void	expand_command(t_token *token, t_dlist *environ)
{
	set_type(token, TKN_CMD);
	set_value(token, get_name_value(get_value(token), environ));
}
