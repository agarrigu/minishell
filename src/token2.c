/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srodrigo <srodrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 14:47:57 by algarrig          #+#    #+#             */
/*   Updated: 2024/07/27 16:35:34 by algarrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include <stdlib.h>
#include "../libft/ft.h"

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
	free((void *)token->value);
	token->value = ft_strdup(value);
}
