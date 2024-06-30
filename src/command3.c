/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srodrigo <srodrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 12:28:20 by srodrigo          #+#    #+#             */
/*   Updated: 2024/06/30 20:40:42 by srodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"
#include "mstypes.h"
#include <unistd.h>
#include "token.h"
#include <stdlib.h>
#include <stdio.h>
#include "env_util.h"
#include "builtins.h"
#include <fcntl.h>
#include <errno.h>
#include <string.h>

char	*get_command(t_dlist *tokens)
{
	while (get_type(get_token(tokens)) != TKN_CMD)
		tokens = tokens->next;
	return (ft_strdup(get_value(get_token(tokens))));
}

char	*get_argument_value(t_token *token, t_dlist *environ)
{
	if (get_type(token) == TKN_NAME)
		return (get_name_value(get_value(token), environ));
	else if (get_type(token) == TKN_DQWORD)
	{
		if (is_expandable(get_value(token)))
			return (expand_dqword(get_value(token)));
		else
			return (ft_strdup(get_value(token)));
	}
	else
		return (ft_strdup(get_value(token)));
}

void	handle_redirections(t_dlist *tokens)
{
	int			fd;
	const char	*file;

	while (tokens)
	{
		if (get_type(get_token(tokens)) == TKN_OPP_LESS)
		{
			file = get_value(get_token(tokens));
			fd = open(file, O_RDONLY);
			if (fd == -1)
			{
				printf("Error: %s: %s\n", strerror(errno), file);
				exit (EXIT_FAILURE);
			}
			(dup2(fd, STDIN_FILENO), close(fd));
		}
		if (get_type(get_token(tokens)) == TKN_OPP_GREAT)
		{
			file = get_value(get_token(tokens));
			fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0666);
			if (fd == -1)
			{
				printf("Error: %s: %s\n", strerror(errno), file);
				exit (EXIT_FAILURE);
			}
			(dup2(fd, STDOUT_FILENO), close(fd));
		}
		if (get_type(get_token(tokens)) == TKN_OPP_DGREAT)
		{
			file = get_value(get_token(tokens));
			fd = open(file, O_WRONLY | O_CREAT | O_APPEND, 0666);
			if (fd == -1)
			{
				printf("Error: %s: %s\n", strerror(errno), file);
				exit (EXIT_FAILURE);
			}
			(dup2(fd, STDOUT_FILENO), close(fd));
		}
		if (get_type(get_token(tokens)) == TKN_IO_HERE)
			printf("Heredoc\n");
		if (get_type(get_token(tokens)) == TKN_OPP_VLINE)
			break ;
		tokens = tokens->next;
	}
}

bool	is_expandable(const char *dqword)
{
	while (*dqword)
	{
		if (*dqword == '$'
			&& *(dqword + 1) != ' '
			&& *(dqword + 1))
			return (true);
		dqword++;
	}
	return (false);
}

char	*expand_dqword(const char *dqword)
{
	char	*dollar;
	char	*expanded;
	char	*name;

	dollar = ft_strchr(dqword, '$');
	expanded = malloc (sizeof(expanded) * (dollar - dqword + 1));
	ft_strlcpy(expanded, dqword, (dollar - dqword + 1));
	dqword = ft_strchr(dollar, ' ');
	if (dqword)
	{
		name = malloc(sizeof(expanded) * (dqword - dollar + 2));
		ft_strlcpy(name, dollar + 1, (dqword - dollar));
		// get name value and concatenate
		if (is_expandable(dqword))
			expand_dqword(dqword);
		//else
			// concatenate dqword
	}
	else
	{
		name = strdup(dollar + 1);
		// get name value and concatenate
	}
	printf("Expanded: \"%s\"\n", expanded);
	return (NULL);
}
