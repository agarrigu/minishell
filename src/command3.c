/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srodrigo <srodrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 12:28:20 by srodrigo          #+#    #+#             */
/*   Updated: 2024/07/01 12:45:13 by srodrigo         ###   ########.fr       */
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
			return (expand_dqword(get_value(token), environ));
		else
			return (ft_strdup(get_value(token)));
	}
	else
		return (ft_strdup(get_value(token)));
}

void	handle_redirections(t_dlist *tokens)
{
	while (tokens)
	{
		if (get_type(get_token(tokens)) == TKN_OPP_LESS)
			infile_redirection(get_token(tokens));
		if (get_type(get_token(tokens)) == TKN_OPP_GREAT)
			outfile_redirection(get_token(tokens));
		if (get_type(get_token(tokens)) == TKN_OPP_DGREAT)
			outfile_appended_redirection(get_token(tokens));
		if (get_type(get_token(tokens)) == TKN_IO_HERE)
			heredoc_redirection(get_token(tokens));
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

char	*expand_dqword(const char *dqword, t_dlist *environ)
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
		expanded = ft_strjoin(expanded, get_name_value(name, environ));
		if (is_expandable(dqword))
			dqword = expand_dqword(dqword, environ);
		expanded = ft_strjoin(expanded, dqword);
	}
	else
	{
		name = strdup(dollar + 1);
		expanded = ft_strjoin(expanded, get_name_value(name, environ));
	}
	return (expanded);
}
