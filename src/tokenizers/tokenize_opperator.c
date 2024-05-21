/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_opperator.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bob </var/mail/bob>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 14:42:08 by bob               #+#    #+#             */
/*   Updated: 2024/05/13 19:41:39 by algarrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../token.h"
#include "../../libft/ft.h"

char	*ft_tokenize_opperator(t_dlist **tokens, char *mark)
{
	t_typtok	type;

	type = TKN_NONE;
	if (*mark == '$')
		type = TKN_OPP_DOLLAR;
	else if (*mark == '<' && *(mark + 1) == '<' && ++mark)
		type = TKN_OPP_DLESS;
	else if (*mark == '<')
		type = TKN_OPP_LESS;
	else if (*mark == '>' && *(mark + 1) == '>' && ++mark)
		type = TKN_OPP_DGREAT;
	else if (*mark == '>')
		type = TKN_OPP_GREAT;
	else if (*mark == '\'')
		type = TKN_OPP_QUOTE;
	else if (*mark == '"')
		type = TKN_OPP_DQUOTE;
	else if (*mark == '|')
		type = TKN_OPP_VLINE;
	ft_addtkntolst(tokens, type, NULL);
	return (++mark);
}
