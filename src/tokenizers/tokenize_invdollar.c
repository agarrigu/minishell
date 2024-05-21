/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_invdollar.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algarrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 21:03:20 by algarrig          #+#    #+#             */
/*   Updated: 2024/05/15 21:27:32 by algarrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/ft.h"
#include "../isses.h"
#include "../token.h"

const char	*ft_tokenize_invdollar(t_dlist **tokens, const char *mark)
{
	const char	*iter;

	iter = mark + 1;
	while (*iter && !ft_isopp(*iter) && ft_isgraph(*iter))
		++iter;
	ft_addtkntolst(tokens, TKN_NAME, ft_substr(mark, 0, iter - mark));
	return (iter);
}
