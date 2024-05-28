/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algarrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 17:47:21 by algarrig          #+#    #+#             */
/*   Updated: 2024/05/28 15:03:17 by bob              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline/readline.h>
#include <readline/history.h>
#include "../libft/ft.h"
#include "signal_util.h"
#include "tokenizer.h"
#include "env_util.h"
#include "cleaners.h"
#include "mstypes.h"
#include <stdlib.h>

int ft_exec(int *last_return_status)
{
	(void) last_return_status;

	return (0);
}

int	ft_parse(t_dlist *tokens)
{
	(void) tokens;

	return (0);
}

void	handle_error(int ms_errno)
{
	(void) ms_errno;
}

int ft_do_stuff(const char* user_input)
{
	static t_dlist	*tokens;
	static int		last_return_status;
	static int		ms_errno;

	if (ft_tokenize(&tokens, user_input) == MS_ERR_HEREDOC_INVDELIM)
		handle_error(MS_ERR_HEREDOC_INVDELIM);
	ms_errno = ft_parse(tokens);
	if (ms_errno != MS_ERR_OK)
		handle_error(ms_errno);
	ms_errno = ft_exec(&last_return_status);
	if (ms_errno != MS_ERR_OK)
		handle_error(ms_errno);
	ft_dlstclear(&tokens, &ft_token_cleaner);
	return (last_return_status);
}

static int	tf_loop(t_dlist **environ)
{
	static char		*user_input;
	static int		last_return_status;

	rl_catch_signals = 0;
	while (42)
	{
		user_input = readline("$>");
		if (!user_input)
			break ;
		if (*user_input)
			(add_history(user_input));
		last_return_status = ft_do_stuff(user_input);
		free(user_input);
	}
	return last_return_status;
}

int	main(int argc, char **argv, char **envp)
{
	static t_dlist	*environ;
	int				status;

	(void) argc;
	(void) argv;
	ft_setup_signal_handling();
	ft_envdup(&environ, envp);
	status = tf_loop(&environ);
	ft_dlstclear(&environ, &ft_kvpr_cleaner);
	rl_clear_history();
	return (status);
}
