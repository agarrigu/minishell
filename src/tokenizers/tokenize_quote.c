/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_quote.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algarrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 18:15:10 by algarrig          #+#    #+#             */
/*   Updated: 2024/07/27 18:04:46 by algarrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/ft.h"
#include "../isses.h"
#include "../token.h"

const char	*ft_tokenize_quote(t_dlist **tokens, const char *mark)
{
	const char	*iter;

	iter = ft_strchr(mark + 1, '\'');
	if (iter)
	{
		++mark;
		ft_addtkntolst(tokens, TKN_QWORD, ft_substr(mark, 0, iter - mark));
		++iter;
	}
	else
	{
		iter = mark + 1;
		while (*iter && ft_isgraph(*iter) && !ft_isopp(*iter))
			++iter;
		ft_addtkntolst(tokens, TKN_WORD, ft_substr(mark, 0, iter - mark));
	}
	return (iter);
}
