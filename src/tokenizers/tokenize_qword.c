/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_qword.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algarrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 19:59:23 by algarrig          #+#    #+#             */
/*   Updated: 2024/05/15 20:49:17 by algarrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/ft.h"
#include "../token.h"

const char	*ft_tokenize_qword(t_dlist **tokens, const char *mark)
{
	const char	*end_mark;

	end_mark = ft_strchr(mark, '\'');
	ft_addtkntolst(tokens, TKN_QWORD, ft_substr(mark, 0, end_mark - mark));
	return (end_mark);
}
