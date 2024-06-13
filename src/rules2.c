/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srodrigo <srodrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 17:47:35 by srodrigo          #+#    #+#             */
/*   Updated: 2024/06/13 18:04:21 by srodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rules.h"
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

bool	is_arg(t_dlist **tokens)
{
	t_token	*token;

	token = get_token(*tokens);
	if (get_type(token) == TKN_WORD
		|| get_type(token) == TKN_QWORD
		|| get_type(token) == TKN_DQWORD)
	{
		if (get_type(token) == TKN_WORD)
			set_type(token, TKN_ARG);
		*tokens = (*tokens)->next;
		return (true);
	}
	else
		return (false);
}
