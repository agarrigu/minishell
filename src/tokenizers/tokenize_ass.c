/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_ass.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srodrigo <srodrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 19:38:15 by algarrig          #+#    #+#             */
/*   Updated: 2024/07/02 15:41:01 by srodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/ft.h"
#include "../token.h"
#include "../isses.h"
#include <stdlib.h>

static const char	*tf_tokenize_equalword(t_dlist **tokens, const char *mark)
{
	const char	*iter;

	iter = mark;
	while (*iter && ft_isgraph(*iter) && (!ft_isopp(*iter) || *iter == '='))
		++iter;
	ft_addtkntolst(tokens, TKN_WORD, ft_substr(mark, 0, iter - mark));
	return (iter);
}

const char	*ft_tokenize_ass(t_dlist **tokens, const char *mark)
{
	t_typtok	prev_tt;
	const char	*tmp;
	t_token		*token;

	if (!*tokens)
		return (tf_tokenize_equalword(tokens, mark));
	prev_tt = ft_last_typtok(*tokens);
	if (*tokens && ft_isass(mark[-1]) && mark[-1] != '$' && (prev_tt == TKN_WORD
			|| prev_tt == TKN_QWORD || prev_tt == TKN_DQWORD
			|| prev_tt == TKN_NAME)
		&& ft_isass(mark[1]))
		return (ft_addtkntolst(tokens, TKN_ASS, NULL), ++mark);
	else if (ft_isass(mark[-1]) && mark[-1] != '$' && prev_tt == TKN_WORD)
	{
		token = (t_token *) ft_dlstlast(*tokens)->data;
		tmp = token->value;
		if (token->value)
			token->value = ft_strjoin(token->value, "=");
		free((void *) tmp);
		return (++mark);
	}
	else
		return (tf_tokenize_equalword(tokens, mark));
}
