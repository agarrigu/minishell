/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srodrigo <srodrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 12:28:20 by srodrigo          #+#    #+#             */
/*   Updated: 2024/06/29 19:33:40 by srodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"
#include "mstypes.h"
#include <unistd.h>
#include "token.h"
#include <stdlib.h>
#include <stdio.h>
#include "env_util.h"
#include "helpers.h"

bool	is_builtin(char *cmd)
{
	printf("Is %s a builtin? ", cmd);
	if (ft_strcmp(cmd, "echo") == 0) // check if in path
		return (true);
	else if (ft_strcmp(cmd, "cd") == 0)
		return (true);
	else if (ft_strcmp(cmd, "pwd") == 0)
		return (true);
	else if (ft_strcmp(cmd, "export") == 0)
		return (true);
	else if (ft_strcmp(cmd, "unset") == 0)
		return (true);
	else if (ft_strcmp(cmd, "env") == 0)
		return (true);
	else if (ft_strcmp(cmd, "exit") == 0)
		return (true);
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

bool	parent_builtin(t_command command)
{
	if (is_builtin(get_command(command.tokens)))
	{
		command.argv = get_arguments(command.tokens);
		return (true);
	}
	else
		return (false);
}
