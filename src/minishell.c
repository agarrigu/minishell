/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algarrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 17:47:21 by algarrig          #+#    #+#             */
/*   Updated: 2024/04/11 16:45:29 by algarrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline/readline.h>
#include "../libft/ft.h"
#include "tokenizer.h"
#include "env_util.h"
#include "cleaners.h"

void	tf_loop(t_dlist **environ)
{
	char			*user_input;
	static t_dlist	*tokens;

	(void) environ;
	while (42)
	{
		user_input = readline("$>");
		if (ft_strcmp(user_input, "exit") == 0)
			break ;
		ft_tokenize(&tokens, user_input);
		ft_dlstclear(&tokens, &ft_token_cleaner);
	}
}

int	main(int argc, char **argv, char **envp)
{
	static t_dlist	*environ;

	(void) argc;
	(void) argv;
	ft_envdup(&environ, envp);
	tf_loop(&environ);
	ft_dlstclear(&environ, &ft_kvpr_cleaner);
	return (0);
}
