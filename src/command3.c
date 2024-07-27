/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srodrigo <srodrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 12:28:20 by srodrigo          #+#    #+#             */
/*   Updated: 2024/07/27 19:46:23 by algarrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"
#include <unistd.h>
#include "token.h"
#include <stdlib.h>
#include <fcntl.h>
#include "cleaners.h"

char	*get_command(t_dlist *tokens, t_dlist *environ)
{
	t_token		*token;
	t_typtok	token_type;

	token = get_token(tokens);
	token_type = get_type(token);
	while (token_type != TKN_CMD && token_type != TKN_ECMD)
	{
		tokens = tokens->next;
		token = get_token(tokens);
		token_type = get_type(token);
	}
	if (token_type == TKN_ECMD)
		expand_command(token, environ);
	return ((char *)get_value(get_token(tokens)));
}

char	*get_argument_value(t_token *token, t_dlist *environ)
{
	char	*tmp;

	if (get_type(token) == TKN_NAME
		|| get_type(token) == TKN_ECMD)
		return (get_name_value(get_value(token), environ));
	else if (get_type(token) == TKN_DQWORD)
	{
		if (is_expandable(get_value(token)))
		{
			tmp = (char *) token->value;
			return (expand_dqword(get_value(token), environ));
			free(tmp);
		}
		else
			return (ft_strdup(get_value(token)));
	}
	else if (get_type(token) == TKN_ASSWORD)
		return (expand_ass(get_value(token), environ));
	else
		return (ft_strdup(get_value(token)));
}

void	handle_redirections(t_dlist *tokens, t_command *cmd, t_dlist **environ)
{
	int	ret;

	ret = 0;
	while (tokens)
	{
		if (get_type(get_token(tokens)) == TKN_OPP_LESS)
			ret = infile_redirection(get_token(tokens));
		if (get_type(get_token(tokens)) == TKN_OPP_GREAT)
			ret = outfile_redirection(get_token(tokens));
		if (get_type(get_token(tokens)) == TKN_OPP_DGREAT)
			ret = outfile_appended_redirection(get_token(tokens));
		if (get_type(get_token(tokens)) == TKN_IO_HERE)
			ret = heredoc_redirection(get_token(tokens));
		if (get_type(get_token(tokens)) == TKN_OPP_VLINE)
			break ;
		tokens = tokens->next;
	}
	if (ret != 0)
	{
		ft_complete_cleaner(cmd, environ);
		exit(ret);
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
	dqword = get_end_name(dollar + 1);
	if (dqword)
	{
		name = malloc(sizeof(expanded) * (dqword - dollar));
		ft_strlcpy(name, dollar + 1, (dqword - dollar));
		expanded = ft_strjoin_freeb(expanded, get_name_value(name, environ));
		if (is_expandable(dqword))
			expanded = ft_strjoin_freeb(expanded,
					expand_dqword(dqword, environ));
		else
			expanded = ft_strjoin_freel(expanded, dqword);
		free(name);
	}
	else
		expanded = ft_strjoin_freeb(expanded,
				get_name_value(ft_strdup(dollar + 1), environ));
	return (expanded);
}
