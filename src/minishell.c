/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algarrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 17:47:21 by algarrig          #+#    #+#             */
/*   Updated: 2024/04/17 15:25:28 by algarrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline/readline.h>
#include <readline/history.h>
#include "../libft/ft.h"
#include "signal_util.h"
#include "tokenizer.h"
#include "env_util.h"
#include "cleaners.h"
#include <stdlib.h>

void	tf_loop(t_dlist **environ)
{
	static char		*user_input;
	static t_dlist	*tokens;

	(void) environ;
	rl_catch_signals = 0;
	while (42)
	{
		user_input = readline("$>");
		if (!user_input)
			break ;
		if (*user_input)
			(add_history(user_input));
		ft_tokenize(&tokens, user_input);
		ft_dlstclear(&tokens, &ft_token_cleaner);
		free(user_input);
	}
}

int	main(int argc, char **argv, char **envp)
{
	static t_dlist	*environ;

	(void) argc;
	(void) argv;
	ft_setup_signal_handling();
	ft_envdup(&environ, envp);
	tf_loop(&environ);
	ft_dlstclear(&environ, &ft_kvpr_cleaner);
	rl_clear_history();
	return (0);
}
