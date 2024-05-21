/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algarrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 14:47:57 by algarrig          #+#    #+#             */
/*   Updated: 2024/05/17 11:36:34 by bob              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include <stdlib.h>
#include "../libft/ft.h"

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
