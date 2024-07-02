/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srodrigo <srodrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 12:28:20 by srodrigo          #+#    #+#             */
/*   Updated: 2024/07/02 14:26:03 by srodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"
#include "mstypes.h"
#include <unistd.h>
#include "token.h"
#include <stdlib.h>
#include <stdio.h>
#include "builtins.h"

void	init_command(t_command *command, t_dlist *tokens)
{
	command->tokens = tokens;
	command->position = 0;
	command->inpipe = 0;
	command->outpipe[WRITE_END] = 0;
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

pid_t	execute_command(t_command *command, t_dlist **environ)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		if (command->inpipe)
			(dup2(command->inpipe, STDIN_FILENO), close(command->inpipe));
		if (command->outpipe[WRITE_END])
		{
			dup2(command->outpipe[WRITE_END], STDOUT_FILENO);
			close(command->outpipe[READ_END]);
			close(command->outpipe[WRITE_END]);
		}
		handle_redirections(command->tokens);
		command->argv = get_arguments(command->tokens, *environ);
		if (is_builtin(command->argv[0]))
			exit (execute_builtin(*command, environ));
		command->filepath = ft_strdup(command->argv[0]);
		// HANDLE WRONG PATHS!!!!!
		if (command->filepath[0] != '/' && command->filepath[0] != '.')
			command->filepath = find_command_path(*environ, command->filepath);
		execve (command->filepath, command->argv, NULL);
		exit (0); // Hanle Error!!!!!!!
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
