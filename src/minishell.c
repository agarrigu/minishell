/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srodrigo <srodrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 17:47:21 by algarrig          #+#    #+#             */
/*   Updated: 2024/06/29 21:26:43 by algarrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline/readline.h>
#include <readline/history.h>
#include "../libft/ft.h"
#include "signal_util.h"
#include "tokenizer.h"
#include "env_util.h"
#include "cleaners.h"
#include "ms_error.h"
#include "builtins.h"
#include <sys/wait.h>
#include "command.h"
#include <stdlib.h>
#include <unistd.h>
#include "rules.h"

bool	ft_parse(t_dlist *tokens)
{
	if (tokens == NULL)
		return (false);
	if (is_command_line(&tokens))
		return (true);
	else
	{
		printf("Syntax error\n");
		return (false);
	}
}

void	execer(t_dlist *tokens, t_dlist **environ)
{
	pid_t		*childs_pid;
	int			commands;
	t_command	command;

	init_command(&command, tokens, environ);
	commands = get_num_commands(tokens);
	if (commands == 1 && is_exit_builtin(&command))
		ft_exit(command.argv, command.environ); // Handle error if exit fails
	childs_pid = malloc(sizeof(childs_pid) * commands);
	while (command.position < commands)
	{
		if (commands - command.position -1)
			pipe(command.outpipe);
		childs_pid[command.position] = execute_command(&command, *environ);
		close_if_fd(command.outpipe[WRITE_END]);
		command.outpipe[WRITE_END] = 0;
		close_if_fd(command.inpipe);
		command.inpipe = command.outpipe[READ_END];
		command.position++;
		command.tokens = get_next_command(command.tokens);
	}
	command.position = -1;
	while (++command.position < commands)
		waitpid(childs_pid[command.position], NULL, 0);
	free(childs_pid);
}

void	handle_error(int ms_errno)
{
	(void) ms_errno;
}

static int	tf_loop(t_dlist **environ)
{
	static char		*user_input;
	static int		last_return_status;
	static t_dlist	*tokens;

	rl_catch_signals = 0;
	while (42)
	{
		user_input = readline("$>");
		if (!user_input)
			break ;
		if (*user_input)
			(add_history(user_input));
		if (ft_tokenize(&tokens, user_input) == MS_ERR_HEREDOC_INVDELIM)
			handle_error(MS_ERR_HEREDOC_INVDELIM);
		if (!ft_parse(tokens))
		{
			ft_dlstclear(&tokens, &ft_token_cleaner);
			continue ;
		}
		execer(tokens, environ);
		ft_dlstclear(&tokens, &ft_token_cleaner);
		free(user_input);
	}
	return (last_return_status);
}

int	main(int argc, char **argv, char **envp)
{
	static t_dlist	*environ;
	static int		status;

	(void) argc;
	(void) argv;
	ft_setup_signal_handling();
	ft_envdup(&environ, envp);
	status = tf_loop(&environ);
	ft_dlstclear(&environ, &ft_kvpr_cleaner);
	rl_clear_history();
	return (status);
}
