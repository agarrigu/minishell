/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srodrigo <srodrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 17:10:01 by srodrigo          #+#    #+#             */
/*   Updated: 2024/07/24 17:40:09 by algarrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include <unistd.h>

bool	is_builtin(char *command)
{
	if (ft_strcmp(command, "echo") == 0
		|| ft_strcmp(command, "cd") == 0
		|| ft_strcmp(command, "pwd") == 0
		|| ft_strcmp(command, "export") == 0
		|| ft_strcmp(command, "unset") == 0
		|| ft_strcmp(command, "env") == 0
		|| ft_strcmp(command, "exit") == 0)
		return (true);
	return (false);
}

int	execute_builtin(t_command command, t_dlist **environ)
{
	if (ft_strcmp(command.argv[0], "echo") == 0)
		return (ft_echo(command.argv, environ));
	else if (ft_strcmp(command.argv[0], "cd") == 0)
		return (ft_cd(command.argv, environ));
	else if (ft_strcmp(command.argv[0], "pwd") == 0)
		return (ft_pwd(command.argv, environ));
	else if (ft_strcmp(command.argv[0], "export") == 0)
		return (ft_export(command.argv, environ));
	else if (ft_strcmp(command.argv[0], "unset") == 0)
		return (ft_unset(command.argv, environ));
	else if (ft_strcmp(command.argv[0], "env") == 0)
		return (ft_env(command.argv, environ));
	else
		return (ft_exit(command.argv, environ));
}

int	exec_parent_builtin(t_command *command, t_dlist **environ)
{
	int	fd;
	int	ret;

	fd = dup(STDOUT_FILENO);
	handle_redirections(command->tokens);
	command->argv = get_arguments(command->tokens, *environ);
	ret = execute_builtin(*command, environ);
	(dup2(fd, STDOUT_FILENO), close(fd));
	return (ret);
}
