/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srodrigo <srodrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 12:28:20 by srodrigo          #+#    #+#             */
/*   Updated: 2024/08/07 19:52:54 by srodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#include "../libft/ft.h"
#include "mstypes.h"
#include "env_util.h"
#include "token.h"
#include "command.h"
#include "command_name.h"
#include "redirections.h"
#include "arguments.h"
#include "builtins.h"
#include "signal_util.h"
#include "cleaners.h"

pid_t	execute_command(t_command *cmd, t_dlist **environ)
{
	pid_t	pid;

	ft_ignore_sigint();
	pid = fork();
	if (pid == 0)
	{
		if (cmd->inpipe)
			(dup2(cmd->inpipe, STDIN_FILENO), close(cmd->inpipe));
		if (cmd->outpipe[WRITE_END])
			(dup2(cmd->outpipe[WRITE_END], STDOUT_FILENO),
				close(cmd->outpipe[READ_END]), close(cmd->outpipe[WRITE_END]));
		handle_redirections(cmd->tokens, cmd, environ);
		cmd->argv = get_arguments(cmd->tokens);
		if (is_builtin(cmd->argv[0]))
			execute_child_builtin(*cmd, environ);
		cmd->filepath = ft_strdup(cmd->argv[0]);
		if (cmd->filepath[0] != '/' && cmd->filepath[0] != '.')
			cmd->filepath = find_command_path(environ, cmd);
		else
			check_command_path(cmd, environ);
		execve (cmd->filepath, cmd->argv, ft_kvprtov(*environ));
		(ft_complete_cleaner(cmd, environ), exit(EXIT_FAILURE));
	}
	return (pid);
}

t_dlist	*get_next_command(t_dlist *tokens)
{
	while (tokens)
	{
		if (get_type(get_token(tokens)) == TKN_OPP_VLINE)
			return (tokens->next);
		tokens = tokens->next;
	}
	return (tokens);
}

void	check_command_path(t_command *cmd, t_dlist **environ)
{
	if (access(cmd->filepath, F_OK) != 0)
	{
		ft_putstr_fd("Error: ", 2);
		ft_putstr_fd(strerror(errno), 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd((char *) cmd->filepath, 2);
		ft_putchar_fd('\n', 2);
		ft_complete_cleaner(cmd, environ);
		exit(errno);
	}
	return ;
}
