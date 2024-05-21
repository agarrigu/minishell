/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_io_out_number.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algarrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 19:36:29 by algarrig          #+#    #+#             */
/*   Updated: 2024/05/15 16:41:31 by algarrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../token.h"
#include "../../libft/ft.h"

const char	*ft_tokenize_out_number(t_dlist **tokens, const char *mark)
{
	const char	*citer;

	citer = mark;
	while (ft_isdigit(*citer))
		++citer;
	ft_addtkntolst(tokens, TKN_OUT_NUMBER, ft_substr(mark, 0, citer - mark));
	return (citer);
}
