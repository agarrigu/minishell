/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srodrigo <srodrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 12:28:20 by srodrigo          #+#    #+#             */
/*   Updated: 2024/06/30 16:57:26 by srodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"
#include "mstypes.h"
#include <unistd.h>
#include "token.h"
#include <stdlib.h>
#include <stdio.h>
#include "env_util.h"

char	*find_command_path(t_dlist *environ, char *cmd)
{
	char	**paths;
	int		i;
	char	*path;
	char	*aux;

	paths = get_env_paths(environ);
	aux = ft_strjoin("/", cmd);
	path = NULL;
	i = 0;
	while (paths[i])
	{
		path = ft_strjoin(paths[i], aux);
		if (access(path, F_OK) == 0)
			break ;
		free(path);
		path = NULL;
		i++;
	}
	(free(aux), ft_freesplit(paths));
	if (path == NULL)
	{
		printf("Error: command not found: %s\n", cmd); // it's not printing if between pipes!!!
		exit(1); // We have to exit with the proper code and then print after catching
	}
	return (path);
}

char	**get_env_paths(t_dlist *environ)
{
	char	**paths;

	while (environ)
	{
		if (ft_strcmp(get_kvpr_key(get_kvpr(environ)), "PATH") == 0)
			paths = ft_split(get_kvpr_value(get_kvpr(environ)), ':');
		environ = environ->next;
	}
	return (paths);
}

void	close_if_fd(int fd)
{
	if (fd)
		close(fd);
}

t_dlist	*get_next_command(t_dlist *tokens) // token
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
	return ("");
}
