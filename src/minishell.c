/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srodrigo <srodrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 17:47:21 by algarrig          #+#    #+#             */
/*   Updated: 2024/06/29 23:10:50 by algarrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <readline/history.h>
#include <readline/readline.h>
#include "../libft/ft.h"
#include "signal_util.h"
#include "tokenizer.h"
#include "env_util.h"
#include "cleaners.h"
#include "ms_error.h"
#include "builtins.h"
#include "command.h"
#include "rules.h"

int	ft_parse(t_dlist *tokens)
{
	if (tokens == NULL)
		return (MS_ERR_OK);
	if (is_command_line(&tokens))
		return (MS_ERR_OK);
	ft_putstr_fd("minishell: Syntax error\n", 2);
	errno = MS_ERR_GENERIC;
	return (MS_ERR_GENERIC);
}

void	execer(t_dlist *tokens, t_dlist **environ, int *status)
{
	pid_t		*childs_pid;
	int			cmds;
	t_command	cmd;

	init_command(&cmd, tokens, environ);
	cmds = get_num_commands(tokens);
	if (cmds == 1 && is_exit_builtin(&cmd) && !ft_exit(cmd.argv, cmd.environ))
		return ;
	childs_pid = malloc(sizeof(childs_pid) * cmds);
	while (cmd.position < cmds)
	{
		if (cmds - cmd.position -1)
			pipe(cmd.outpipe);
		childs_pid[cmd.position] = execute_command(&cmd, *environ, status);
		close_if_fd(cmd.outpipe[WRITE_END]);
		cmd.outpipe[WRITE_END] = 0;
		close_if_fd(cmd.inpipe);
		cmd.inpipe = cmd.outpipe[READ_END];
		cmd.position++;
		cmd.tokens = get_next_command(cmd.tokens);
	}
	cmd.position = -1;
	while (++cmd.position < cmds)
		waitpid(childs_pid[cmd.position], NULL, 0);
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
	static int		ms_errno;
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
		if (ft_parse(tokens) == MS_ERR_OK)
			execer(tokens, environ, &last_return_status);
		if (errno > 4200)
			handle_error(errno);
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
