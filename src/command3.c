/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srodrigo <srodrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 12:28:20 by srodrigo          #+#    #+#             */
/*   Updated: 2024/06/29 21:52:38 by srodrigo         ###   ########.fr       */
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

bool	execute_builtin(t_command command)
{
	if (ft_strcmp(command.argv[0], "echo") == 0)
		ft_echo(command.argv, command.environ);
	else if (ft_strcmp(command.argv[0], "cd") == 0)
		ft_cd(command.argv, command.environ);
	else if (ft_strcmp(command.argv[0], "pwd") == 0)
		ft_pwd(command.argv, command.environ);
	else if (ft_strcmp(command.argv[0], "export") == 0)
		ft_export(command.argv, command.environ);
	else if (ft_strcmp(command.argv[0], "unset") == 0)
		ft_unset(command.argv, command.environ);
	else if (ft_strcmp(command.argv[0], "env") == 0)
		ft_env(command.argv, command.environ);
	else if (ft_strcmp(command.argv[0], "exit") == 0)
		ft_exit(command.argv, command.environ);
	else
		return (false);
	return (true);
}

char	*get_command(t_dlist *tokens)
{
	while (get_type(get_token(tokens)) != TKN_CMD)
		tokens = tokens->next;
	return (ft_strdup(get_value(get_token(tokens))));
}

bool	is_exit_builtin(t_command *command)
{
	if (ft_strcmp(get_command(command->tokens), "exit") == 0)
	{
		command->argv = get_arguments(command->tokens);
		return (true);
	}
	else
		return (false);
}
