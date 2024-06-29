/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_dquote.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srodrigo <srodrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 18:25:38 by algarrig          #+#    #+#             */
/*   Updated: 2024/06/29 22:14:33 by srodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/ft.h"
#include "../isses.h"
#include "../token.h"

const char	*ft_tokenize_dquote(t_dlist **tokens, const char *mark)
{
	const char	*iter;

	iter = ft_strchr(mark + 1, '"');
	if (iter)
	{
		++mark;
		ft_addtkntolst(tokens, TKN_DQWORD, ft_substr(mark, 0, iter - mark));
		++iter;
	}
	else
	{
		iter = mark;
		while (*iter && ft_isgraph(*iter) && !ft_isopp(*iter))
			++iter;
		ft_addtkntolst(tokens, TKN_WORD, ft_substr(mark, 0, iter - mark));
	}
	return (iter);
}
