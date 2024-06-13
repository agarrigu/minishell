/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srodrigo <srodrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 14:47:57 by algarrig          #+#    #+#             */
/*   Updated: 2024/06/13 18:09:21 by srodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include <stdlib.h>
#include "../libft/ft.h"
#include "cleaners.h"

t_token	*ft_new_token(t_typtok type, const char *value)
{
	t_token	*token;

	token = malloc(sizeof(*token));
	*token = (t_token){type, value};
	return (token);
}

t_typtok	ft_last_typtok(t_dlist *tokens)
{
	if (!tokens)
	{
		return (TKN_NONE);
	}
	return (((t_token *) ft_dlstlast(tokens)->data)->type);
}

void	ft_addtkntolst(t_dlist **tokens, t_typtok type, void *data)
{
	ft_dlstadd_back(tokens, ft_dlstnew(ft_new_token(type, data)));
}

t_token	*get_token(t_dlist *tokens)
{
	return ((t_token *) tokens->data);
}

t_typtok	get_type(t_token *token)
{
	return (token->type);
}

void	set_type(t_token *token, t_typtok type)
{
	token->type = type;
}

const char	*get_value(t_token *token)
{
	return (token->value);
}

void	set_value(t_token *token, const char *value)
{
	token->value = ft_strdup(value);
}

void	delete_node(t_dlist *tokens)
{
	if (tokens->prev)
		(tokens->prev)->next = tokens->next;
	if (tokens->next)
		(tokens->next)->prev = tokens->prev;
	ft_token_cleaner(get_token(tokens));
	free(tokens);
}
