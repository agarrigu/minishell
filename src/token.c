/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algarrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 14:47:57 by algarrig          #+#    #+#             */
/*   Updated: 2024/04/21 15:20:24 by algarrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include <stdlib.h>
#include "../libft/ft.h"

t_token	*ft_new_token(t_typtok type, const char *value)
{
	t_token	*token;

	token = malloc(sizeof(*token));
	token->type = type;
	token->value = value;
	return (token);
}

t_token	*ft_has_token(t_dlist *tokens, t_typtok ttype)
{
	t_token	*token;

	while (tokens)
	{
		token = (t_token *) tokens->data;
		if (token->type == ttype)
			return (token);
		tokens = tokens->next;
	}
	return (NULL);
}
