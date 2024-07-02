/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_word.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bob </var/mail/bob>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 17:57:42 by bob               #+#    #+#             */
/*   Updated: 2024/07/02 03:56:40 by algarrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/ft.h"
#include "../isses.h"
#include "../token.h"

char	*ft_tokenize_word(t_dlist **tokens, char *mark)
{
	char	*iter;

	iter = mark;
	while (*iter && !ft_isopp(*iter) && ft_isgraph(*iter))
		++iter;
	if (mark == iter)
		return (iter);
	ft_addtkntolst(tokens, TKN_WORD, ft_substr(mark, 0, iter - mark));
	return (iter);
}
