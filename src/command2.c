/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srodrigo <srodrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 12:28:20 by srodrigo          #+#    #+#             */
/*   Updated: 2024/08/07 13:22:16 by srodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"
#include <unistd.h>
#include "token.h"
#include <stdlib.h>
#include <stdio.h>
#include "env_util.h"
#include "cleaners.h"

/* NOTE: linking problems with ft_putend_fd (as previously)
   We have to exit with the proper code
*/
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

void	close_if_fd(int fd)
{
	if (fd)
		close(fd);
}

t_dlist	*get_next_command(t_dlist *tokens)
{
	while (tokens)
	{
		if (get_type(get_token(tokens)) == TKN_OPP_VLINE)
			return (tokens->next);
		tokens = tokens->next;
	}
	return (tokens);
}

char	*get_name_value(const char *name, t_dlist *environ)
{
	while (environ)
	{
		if (ft_strcmp(get_kvpr_key(get_kvpr(environ)), name) == 0)
			return (ft_strdup(get_kvpr_value(get_kvpr(environ))));
		environ = environ->next;
	}
	return (ft_strdup(""));
}
