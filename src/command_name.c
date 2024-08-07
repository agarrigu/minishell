/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_name.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srodrigo <srodrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 18:09:46 by srodrigo          #+#    #+#             */
/*   Updated: 2024/08/07 19:58:40 by srodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "../libft/ft.h"
#include "env_util.h"
#include "token.h"
#include "command.h"
#include "command_name.h"
#include "cleaners.h"


char	*get_command(t_dlist *tokens)
{
	t_token		*token;
	t_typtok	token_type;

	token = get_token(tokens); // refactorize!!!!
	token_type = get_type(token);
	while (token_type != TKN_CMD)
	{
		tokens = tokens->next;
		token = get_token(tokens);
		token_type = get_type(token);
	}
	return ((char *)get_value(get_token(tokens)));
}

char	*find_command_path(t_dlist **environ, t_command *cmd)
{
	char	**paths;
	int		i;
	char	*path;
	char	*aux;

	path = NULL;
	paths = get_env_paths(*environ);
	aux = ft_strjoin("/", cmd->filepath);
	i = -1;
	while (paths && paths[++i])
	{
		path = ft_strjoin(paths[i], aux);
		if (access(path, F_OK) == 0)
			break ;
		free(path);
		path = NULL;
	}
	(free(aux), ft_freesplit(paths));
	if (path == NULL || paths == NULL)
	{
		ft_putstr_fd("Error: command not found: ", 2);
		(ft_putstr_fd(cmd->filepath, 2), ft_putchar_fd('\n', 2));
		(ft_complete_cleaner(cmd, environ), exit(1));
	}
	return (path);
}

char	**get_env_paths(t_dlist *environ)
{
	char	**paths;

	paths = NULL;
	while (environ)
	{
		if (ft_strcmp(get_kvpr_key(get_kvpr(environ)), "PATH") == 0)
		{
			paths = ft_split(get_kvpr_value(get_kvpr(environ)), ':');
			return (paths);
		}
		environ = environ->next;
	}
	return (NULL);
}

