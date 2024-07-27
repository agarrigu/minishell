/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algarrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 20:39:18 by algarrig          #+#    #+#             */
/*   Updated: 2024/07/27 16:44:32 by algarrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/ft.h"
#include "token.h"
#include "isses.h"
#include "tokenizers.h"

int	ft_tokenize(t_dlist **tokens, const char *s)
{
	while (*s)
	{
		if (*s == '\'')
			s = ft_tokenize_quote(tokens, s);
		else if (*s == '"')
			s = ft_tokenize_dquote(tokens, s);
		else if (*s == '$')
			s = ft_tokenize_dollar(tokens, s);
		else if (*s == '=')
			s = ft_tokenize_ass(tokens, s);
		else if (ft_isopp(*s))
			s = ft_tokenize_opperator(tokens, s);
		else if (ft_last_typtok(*tokens) == TKN_OPP_DLESS)
		{
			s = ft_tokenize_io_here(tokens, s);
			if (!s)
				return (-1);
		}
		else if (ft_isgraph(*s))
			s = ft_tokenize_word(tokens, s);
		else
			++s;
	}
	return (0);
}
