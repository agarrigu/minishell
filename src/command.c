/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srodrigo <srodrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 12:28:20 by srodrigo          #+#    #+#             */
/*   Updated: 2024/07/25 17:52:26 by algarrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"
#include "mstypes.h"
#include <unistd.h>
#include "token.h"
#include <stdlib.h>
#include <stdio.h>
#include "builtins.h"

void	init_command(t_command *cmd, t_dlist *tokens)
{
	cmd->argv = NULL;
	cmd->filepath = NULL;
	cmd->tokens = tokens;
	cmd->position = 0;
	cmd->inpipe = 0;
	cmd->outpipe[WRITE_END] = 0;
	cmd->childs_pid = NULL;
}

int	get_num_commands(t_dlist *tokens)
{
	int			ncmd;

	ncmd = 0;
	while (tokens)
	{
		if (get_type(get_token(tokens)) == TKN_OPP_VLINE)
			ncmd++;
		tokens = tokens->next;
	}
	return (ncmd + 1);
}

/* NOTE: If EXECVE fails it has to exit() whith the proper error
   and I guess there has to be some malloc'd cleaning */
pid_t	execute_command(t_command *cmd, t_dlist **environ)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		if (cmd->inpipe)
			(dup2(cmd->inpipe, STDIN_FILENO), close(cmd->inpipe));
		if (cmd->outpipe[WRITE_END])
		{
			dup2(cmd->outpipe[WRITE_END], STDOUT_FILENO);
			(close(cmd->outpipe[READ_END]), close(cmd->outpipe[WRITE_END]));
		}
		handle_redirections(cmd->tokens);
		cmd->argv = get_arguments(cmd->tokens, *environ);
		if (is_builtin(cmd->argv[0]))
			execute_child_builtin(*cmd, environ);
		cmd->filepath = ft_strdup(cmd->argv[0]);
		if (cmd->filepath[0] != '/' && cmd->filepath[0] != '.')
			cmd->filepath = find_command_path(*environ, cmd->filepath);
		else
			check_command_path(cmd->filepath);
		execve (cmd->filepath, cmd->argv, NULL);
		exit (0);
	}
	return (pid);
}

char	**get_arguments(t_dlist *tokens, t_dlist *environ)
{
	int		narg;
	char	**argv;

	narg = get_num_arguments(tokens) + 1;
	argv = malloc (sizeof(*argv) * (narg + 1));
	argv[narg] = NULL;
	narg = 0;
	while (tokens)
	{
		if (get_type(get_token(tokens)) == TKN_CMD
			|| get_type(get_token(tokens)) == TKN_ECMD
			|| get_type(get_token(tokens)) == TKN_ARG
			|| get_type(get_token(tokens)) == TKN_QWORD
			|| get_type(get_token(tokens)) == TKN_NAME
			|| get_type(get_token(tokens)) == TKN_DQWORD
			|| get_type(get_token(tokens)) == TKN_ASSWORD)
		{
			argv[narg] = get_argument_value(get_token(tokens), environ);
			narg++;
		}
		if (get_type(get_token(tokens)) == TKN_OPP_VLINE)
			break ;
		tokens = tokens->next;
	}
	return (argv);
}

int	get_num_arguments(t_dlist *tokens)
{
	int	narg;

	narg = 0;
	while (tokens)
	{
		if (get_type(get_token(tokens)) == TKN_ARG
			|| get_type(get_token(tokens)) == TKN_DQWORD
			|| get_type(get_token(tokens)) == TKN_QWORD
			|| get_type(get_token(tokens)) == TKN_NAME
			|| get_type(get_token(tokens)) == TKN_ASSWORD)
			narg++;
		if (get_type(get_token(tokens)) == TKN_OPP_VLINE)
			break ;
		tokens = tokens->next;
	}
	return (narg);
}
