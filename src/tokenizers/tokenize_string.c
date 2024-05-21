/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algarrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 13:47:50 by algarrig          #+#    #+#             */
/*   Updated: 2024/05/15 17:56:51 by algarrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/ft.h"
#include "../tokenizers.h"
#include "../token.h"

const char	*ft_tokenize_string(t_dlist **tokens, const char *mark)
{
	t_typtok	last_type;
	t_typtok	penult_type;
	t_dlist		*last_node;

	last_type = ft_last_typtok(*tokens);
	last_node = ft_dlstlast(*tokens);
	penult_type = TKN_NONE;
	if (last_node && last_node->prev)
		penult_type = ((t_token *) last_node->prev->data)->type;
	if (last_type == TKN_OPP_QUOTE && penult_type != TKN_QWORD)
		mark = ft_tokenize_qword(tokens, mark);
	else if (last_type == TKN_OPP_DQUOTE && penult_type != TKN_DQWORD)
		mark = ft_tokenize_dqword(tokens, mark);
	else if (last_type == TKN_OPP_DOLLAR)
		mark = ft_tokenize_name(tokens, mark);
	else
		mark = ft_tokenize_word(tokens, mark);
	return (mark);
}
