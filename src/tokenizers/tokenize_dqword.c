/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_dqword.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algarrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 19:59:23 by algarrig          #+#    #+#             */
/*   Updated: 2024/05/21 18:46:59 by bob              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/ft.h"
#include "../token.h"
#include "../cleaners.h"

const char	*ft_tokenize_dqword(t_dlist **tokens, const char *mark)
{
	const char	*end_mark;

	end_mark = ft_strchr(mark, '"');
	ft_dlstdellast(tokens, &ft_token_cleaner);
	ft_addtkntolst(tokens, TKN_DQWORD, ft_substr(mark, 0, end_mark - mark));
	return (++end_mark);
}
