/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algarrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 20:39:18 by algarrig          #+#    #+#             */
/*   Updated: 2024/05/21 14:29:30 by bob              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/ft.h"
#include "mstypes.h"
#include "token.h"
#include "isses.h"
#include "tokenizers.h"

static int	ft_is_digs_till_oppchr(const char *mark, char c)
{
	while (ft_isdigit(*mark))
		++mark;
	while (ft_isblank(*mark))
		++mark;
	return (*mark == c);
}

int	ft_tokenize(t_dlist **tokens, const char *s)
{
	int	ms_errno;

	ms_errno = MS_ERR_OK;
	while (*s)
	{
		if (*s == '\'' && !ft_strchr(s + 1, '\''))
			s = ft_tokenize_ucquote(tokens, s);
		else if (*s == '"' && !ft_strchr(s + 1, '"'))
			s = ft_tokenize_ucdquote(tokens, s);
		else if (*s == '$' && !ft_isname(s[1]))
			s = ft_tokenize_invdollar(tokens, s);
		else if (ft_isopp(*s))
			s = ft_tokenize_opperator(tokens, s);
		else if (ft_last_typtok(*tokens) == TKN_OPP_DLESS)
			s = ft_tokenize_io_here(tokens, s, &ms_errno);
		else if (ft_isdigit(*s) && ft_is_digs_till_oppchr(s, '>'))
			s = ft_tokenize_in_number(tokens, s);
		else if (ft_isdigit(*s) && ft_is_digs_till_oppchr(s, '<'))
			s = ft_tokenize_out_number(tokens, s);
		else if (ft_isgraph(*s))
			s = ft_tokenize_string(tokens, s);
		else
			++s;
	}
	return (ms_errno);
}
