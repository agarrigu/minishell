/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_dollar.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algarrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 18:29:12 by algarrig          #+#    #+#             */
/*   Updated: 2024/06/26 19:15:54 by algarrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/ft.h"
#include "../isses.h"
#include "../token.h"

const char	*ft_tokenize_dollar(t_dlist **tokens, const char *mark)
{
	const char	*iter;

	iter = mark;
	if (ft_isname(iter[1]))
	{
		++iter;
		++mark;
		while (ft_isname(*iter))
			++iter;
		ft_addtkntolst(tokens, TKN_NAME, ft_substr(mark, 0, iter - mark));
	}
	else
	{
		while (*iter && !ft_isopp(*iter) && ft_isgraph(*iter))
			++iter;
		ft_addtkntolst(tokens, TKN_WORD, ft_substr(mark, 0, iter - mark));
	}
	return (iter);
}
