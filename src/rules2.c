/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srodrigo <srodrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 17:47:35 by srodrigo          #+#    #+#             */
/*   Updated: 2024/07/02 04:31:08 by algarrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rules.h"
#include "cleaners.h"
#include <stdlib.h>
//#include "helpers.h"

bool	is_args_list(t_dlist **tokens)
{
	t_dlist	*start;

	start = *tokens;
	if (*tokens == NULL)
		return (true);
	if (is_arg(tokens) || is_io_redir(tokens))
		return (is_args_list(tokens));
	else if (start != *tokens)
		return (false);
	return (true);
}

static const char *get_value4ass(t_token *token)
{
	if (token->type == TKN_NAME)
		return (ft_strjoin("$", token->value));
	if (token->type == TKN_QWORD)
		return (ft_concat(3, "'", token->value, "'"));
	else
		return (ft_strdup(token->value));
}

static void	do_the_ass_thing(t_dlist **tokens)
{
	t_token	*token;
	const char *prev;
	const char *next;
	const char *ass;
	
	token = get_token(*tokens);
	prev = get_value4ass(get_token((*tokens)->prev));
	next = get_value4ass(get_token((*tokens)->next));
	ass = ft_concat(3, prev, "=", next);
	token->type = TKN_ASSWORD;
	token->value = ass;
	free((void *) prev);
	free((void *) next);
	ft_removedlst(&(*tokens)->next, &ft_token_cleaner);
	ft_removedlst(&(*tokens)->prev, &ft_token_cleaner);
}

bool	is_arg(t_dlist **tokens)
{
	t_token	*token;

	token = get_token(*tokens);
	if (get_type(token) == TKN_WORD
		|| get_type(token) == TKN_QWORD
		|| get_type(token) == TKN_DQWORD
		|| get_type(token) == TKN_NAME)
	{
		if (get_type(token) == TKN_WORD)
			set_type(token, TKN_ARG);
		*tokens = (*tokens)->next;
		return (true);
	}
	else if (get_type(token) == TKN_ASS
		&& get_type(get_token((*tokens)->prev))!= TKN_CMD)
	{
		do_the_ass_thing(tokens);
		*tokens = (*tokens)->next;
		return (true);
	}
	else
		return (false);
}
