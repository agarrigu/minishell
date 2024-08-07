/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srodrigo <srodrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 17:10:01 by srodrigo          #+#    #+#             */
/*   Updated: 2024/08/07 23:01:33 by srodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include "builtins.h"
#include "redirections.h"
#include "arguments.h"
#include "cleaners.h"

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

int	exec_parent_builtin(t_command *command, t_dlist **environ)
{
	int	stdin_fd;
	int	stdout_fd;
	int	ret;

	stdin_fd = dup(STDIN_FILENO);
	stdout_fd = dup(STDOUT_FILENO);
	handle_redirections(command->tokens, command, environ);
	command->argv = get_arguments(command->tokens);
	ret = execute_builtin(*command, environ);
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	dup2(stdin_fd, STDIN_FILENO);
	dup2(stdout_fd, STDOUT_FILENO);
	return (ret);
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
		return (ft_exit(command.argv, environ, &command));
}

void	execute_child_builtin(t_command command, t_dlist **environ)
{
	int		ret;

	ret = execute_builtin(command, environ);
	ft_complete_cleaner(&command, environ);
	exit(ret);
}
