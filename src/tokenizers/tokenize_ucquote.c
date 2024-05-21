/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_ucquote.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algarrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 20:48:23 by algarrig          #+#    #+#             */
/*   Updated: 2024/05/15 21:34:06 by algarrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/ft.h"
#include "../isses.h"
#include "../token.h"

const char	*ft_tokenize_ucquote(t_dlist **tokens, const char *mark)
{
	const char	*citer;

	citer = mark + 1;
	while (*citer && ft_isgraph(*citer) && !ft_isopp(*citer))
		++citer;
	ft_addtkntolst(tokens, TKN_WORD, ft_substr(mark, 0, citer - mark));
	return (citer);
}
