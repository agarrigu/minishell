/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_name.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bob </var/mail/bob>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 15:24:02 by bob               #+#    #+#             */
/*   Updated: 2024/05/15 21:27:23 by algarrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/ft.h"
#include "../isses.h"
#include "../token.h"

const char	*ft_tokenize_name(t_dlist **tokens, const char *mark)
{
	const char	*iter;

	iter = mark + 1;
	while (ft_isname(*iter))
		++iter;
	ft_addtkntolst(tokens, TKN_NAME, ft_substr(mark, 0, iter - mark));
	return (iter);
}
