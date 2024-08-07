/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srodrigo <srodrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 18:10:35 by srodrigo          #+#    #+#             */
/*   Updated: 2024/08/07 19:54:46 by srodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../libft/ft.h"
#include "mstypes.h"
#include "command_line.h"
#include "command.h"
#include "token.h"

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

void	pipes_and_execute(int commands, t_command *command, t_dlist **environ)
{
	while (command->position < commands)
	{
		if (commands - command->position -1)
			pipe(command->outpipe);
		command->childs_pid[command->position]
			= execute_command(command, environ);
		close_if_fd(command->outpipe[WRITE_END]);
		command->outpipe[WRITE_END] = 0;
		close_if_fd(command->inpipe);
		command->inpipe = command->outpipe[READ_END];
		command->position++;
		command->tokens = get_next_command(command->tokens);
	}
}

void	close_if_fd(int fd)
{
	if (fd)
		close(fd);
}
