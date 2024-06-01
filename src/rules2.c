/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules 2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srodrigo <srodrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 17:47:35 by srodrigo          #+#    #+#             */
/*   Updated: 2024/06/01 17:48:00 by srodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rules.h"

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
	t_token	*token_data;

	token_data = (*tokens)->data;
	if (token_data->type == TKN_WORD
		|| token_data->type == TKN_QWORD
		|| token_data->type == TKN_DQWORD)
	{
		*tokens = (*tokens)->next;
		return (true);
	}
	else
		return (false);
}
