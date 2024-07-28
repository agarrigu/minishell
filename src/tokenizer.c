/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algarrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 20:39:18 by algarrig          #+#    #+#             */
/*   Updated: 2024/07/28 19:20:28 by algarrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "../libft/ft.h"
#include "token.h"
#include "isses.h"

static void	tf_tokenize_opperator(t_dlist **tokens, const char *mark, int len)
{
	if (len == 1 && *mark == '<')
		ft_addtkntolst(tokens, TKN_OPP_LESS, NULL);
	else if (len == 1 && *mark == '>')
		ft_addtkntolst(tokens, TKN_OPP_GREAT, NULL);
	else if (len == 1 && *mark == '|')
		ft_addtkntolst(tokens, TKN_OPP_VLINE, NULL);
	else if (len == 2 && ft_strncmp("<<", mark, 2))
		ft_addtkntolst(tokens, TKN_OPP_DLESS, NULL);
	else if (len == 2 && ft_strncmp(">>", mark, 2))
		ft_addtkntolst(tokens, TKN_OPP_DGREAT, NULL);
}

static const char	*tf_categorize_token(t_dlist **tokens, const char *mark,
	size_t len)
{
	if ((len == 1 && ft_isopp(*mark)) || (len == 2 && ft_islongopp(mark)))
		tf_tokenize_opperator(tokens, mark, len);
	else if (ft_isgraph(*mark))
		ft_addtkntolst(tokens, TKN_WORD, ft_strndup(mark, len));
	return (mark + len);
}

static const char	*tf_tokenize_quote(const char *s)
{
	if (*s == '\'')
		return (ft_strchr(++s, '\''));
	if (*s == '"')
		return (ft_strchr(++s, '"'));
	return (++s);
}

void	ft_tokenize(t_dlist **tokens, const char *s)
{
	const char	*mark;

	if (!s || !*s)
		return ;
	mark = s++;
	while (*s && mark)
	{
		if (ft_is_opp_cand(s[-1], s[0]))
			;
		else if (ft_isopp(s[-1]) && !ft_isopp(s[0]))
			mark = tf_categorize_token(tokens, mark, s - mark);
		else if ((*s == '\'' && ft_strchr(s, '\''))
			|| (*s == '"' && ft_strchr(s, '"')))
			s = tf_tokenize_quote(s);
		else if (ft_isopp(*s))
			mark = tf_categorize_token(tokens, mark, s - mark);
		else if (ft_isblank(*s))
			mark = tf_categorize_token(tokens, mark, s - mark);
		else if (mark != s && ft_isgraph(s[-1]))
			;
		else
			mark = s;
		++s;
	}
	tf_categorize_token(tokens, mark, s - mark);
}
