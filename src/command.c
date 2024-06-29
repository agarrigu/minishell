/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srodrigo <srodrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 12:28:20 by srodrigo          #+#    #+#             */
/*   Updated: 2024/06/29 13:05:08 by srodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"
#include "mstypes.h"
#include <unistd.h>
#include "token.h"
#include <stdlib.h>

void	init_command(t_command *command, t_dlist *tokens)
{
	command->tokens = tokens;
	command->position = 0;
	command->inpipe_read = 0;
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

pid_t	execute_command(t_command *command, t_dlist *environ)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		if (command->inpipe_read)
		{
			dup2(command->inpipe_read, STDIN_FILENO);
			close(command->inpipe_read);
		}
		if (command->outpipe[WRITE_END])
		{
			dup2(command->outpipe[WRITE_END], STDOUT_FILENO);
			close(command->outpipe[READ_END]);
			close(command->outpipe[WRITE_END]);
		}
		command->argv = get_arguments(command->tokens);
		command->filepath = ft_strdup(command->argv[0]);
		if (command->filepath[0] != '/' && command->filepath[0] != '.')
			command->filepath = find_command_path(environ, command->filepath);
		execve (command->filepath, command->argv, NULL);
		exit (0);
	}
	return (pid);
}

char	**get_arguments(t_dlist *tokens)
{
	int		narguments;
	char	**argv;

	narguments = get_num_arguments(tokens);
	argv = malloc (sizeof(*argv) * (narguments + 2));
	argv[narguments + 1] = NULL;
	narguments = 1;
	while (tokens)
	{
		if (get_type(get_token(tokens)) == TKN_CMD)
			argv[0] = ft_strdup(get_value(get_token(tokens)));
		if (get_type(get_token(tokens)) == TKN_ARG)
		{
			argv[narguments] = ft_strdup(get_value(get_token(tokens)));
			narguments++;
		}
		if (get_type(get_token(tokens)) == TKN_OPP_VLINE)
			break ;
		tokens = tokens->next;
	}
	return (argv);
}

int	get_num_arguments(t_dlist *tokens)
{
	int	narguments;

	narguments = 0;
	while (tokens)
	{
		if (get_type(get_token(tokens)) == TKN_ARG)
			narguments++;
		if (get_type(get_token(tokens)) == TKN_OPP_VLINE)
			break ;
		tokens = tokens->next;
	}
	return (narguments);
}
