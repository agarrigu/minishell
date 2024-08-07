/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srodrigo <srodrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:52:20 by srodrigo          #+#    #+#             */
/*   Updated: 2024/08/08 00:05:18 by srodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rules.h"
#include <stdio.h>

/*
	Grammar
	
	command_line -> 		command TKN_OPP_VLINE command_line
							| command

	command ->				io_redir_list command_name args_list

	io_redir_list ->		io_redir io_redir_list
							| io_redir
							| e

	io_redir ->				TKN_OPP_LESS TKN_WORD
							| TKN_OPP_DLESS TKN_IO_HERE
							| TKN_OPP_GREAT TKN_WORD
							| TKN_OPP_DGREAT TKN_WORD

	command_name ->			TKN_WORD

	args_list ->			arg args_list
							| io_redir args_list
							| arg
							| io_redir
							| e
	
	arg ->					TKN_WORD
*/

bool	is_command_line(t_dlist **tokens)
{
	t_token	*token;

	if (*tokens == NULL)
		return (false);
	if (is_command(tokens))
	{
		if (*tokens == NULL)
			return (true);
		token = get_token(*tokens);
		if (get_type(token) == TKN_OPP_VLINE)
		{
			*tokens = (*tokens)->next;
			if (is_command_line(tokens))
				return (true);
		}
	}
	return (false);
}

bool	is_command(t_dlist **tokens)
{
	if (!is_io_redir_list(tokens))
		return (false);
	if (*tokens == NULL)
		return (false);
	if (!is_command_name(tokens))
		return (false);
	return (is_args_list(tokens));
}

bool	is_io_redir_list(t_dlist **tokens)
{
	t_dlist	*start;

	start = *tokens;
	if (*tokens == NULL)
		return (true);
	if (is_io_redir(tokens))
	{
		if (*tokens == NULL)
			return (false);
		if (is_io_redir_list(tokens))
			return (true);
		else
			return (false);
	}
	else if (start != *tokens)
		return (false);
	return (true);
}

bool	is_io_redir(t_dlist **tokens)
{
	t_token		*token;
	t_typtok	aux_type;

	token = get_token(*tokens);
	aux_type = get_type(token);
	if (is_redir_operation(aux_type))
	{
		*tokens = (*tokens)->next;
		if (*tokens == NULL)
			return (false);
		token = get_token(*tokens);
		if ((get_type(token) == TKN_WORD && aux_type != TKN_OPP_DLESS)
			|| (get_type(token) == TKN_IO_HERE && aux_type == TKN_OPP_DLESS))
		{
			set_value(get_token((*tokens)->prev), get_value(token));
			*tokens = (*tokens)->prev;
			delete_node((*tokens)->next);
			*tokens = (*tokens)->next;
		}
		else
			return (false);
	}
	else
		return (false);
	return (true);
}

bool	is_redir_operation(t_typtok tiktoker)
{
	return (tiktoker == TKN_OPP_LESS
		|| tiktoker == TKN_OPP_GREAT
		|| tiktoker == TKN_OPP_DGREAT
		|| tiktoker == TKN_OPP_DLESS);
}
