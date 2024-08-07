/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srodrigo <srodrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 12:28:20 by srodrigo          #+#    #+#             */
/*   Updated: 2024/08/07 19:47:42 by srodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include "mstypes.h"
#include "token.h"
#include "redirections.h"
#include "command.h"
#include "cleaners.h"


void	handle_redirections(t_dlist *tokens, t_command *cmd, t_dlist **environ)
{
	int	ret;

	ret = 0;
	while (tokens)
	{
		if (get_type(get_token(tokens)) == TKN_OPP_LESS)
			ret = infile_redirection(get_token(tokens));
		if (get_type(get_token(tokens)) == TKN_OPP_GREAT)
			ret = outfile_redirection(get_token(tokens));
		if (get_type(get_token(tokens)) == TKN_OPP_DGREAT)
			ret = outfile_appended_redirection(get_token(tokens));
		if (get_type(get_token(tokens)) == TKN_IO_HERE)
			ret = heredoc_redirection(get_token(tokens));
		if (get_type(get_token(tokens)) == TKN_OPP_VLINE)
			break ;
		tokens = tokens->next;
	}
	if (ret != 0)
	{
		ft_complete_cleaner(cmd, environ);
		exit(ret);
	}
}

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

