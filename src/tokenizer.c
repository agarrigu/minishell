/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algarrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 20:39:18 by algarrig          #+#    #+#             */
/*   Updated: 2024/04/20 20:40:25 by algarrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/ft.h"
#include <stdlib.h>
#include "token.h"

int	ft_isopp(int c)
{
	return (c == '>' || c == '<' || c == '!' || c == '$' || c == '|'
		|| c == '\'' || c == '"');
}

static char	*tf_tokenize_word(t_dlist **tokens, char *mark)
{
	char	*iter;
	char	*value;

	iter = mark;
	while (*iter && !ft_isopp(*iter) && !ft_isspace(*iter))
		++iter;
	value = ft_substr(mark, 0, iter - mark);
	ft_dlstadd_back(tokens, ft_dlstnew(ft_new_token(WORD, value)));
	return (iter);
}

static char	*tf_tokenize_symbol(t_dlist **tokens, char *mark)
{
	t_typtok	type;

	type = NONE;
	if (ft_strncmp(mark, "!", 1) == 0)
		type = BANG;
	else if (ft_strncmp(mark, ">>", 2) == 0 && ++mark)
		type = DGREAT;
	else if (ft_strncmp(mark, ">", 1) == 0)
		type = GREAT;
	else if (ft_strncmp(mark, "<<", 2) == 0 && ++mark)
		type = DLESS;
	else if (ft_strncmp(mark, "<", 1) == 0)
		type = LESS;
	else if (ft_strncmp(mark, "$", 1) == 0)
		type = DOLLAR;
	else if (ft_strncmp(mark, "|", 1) == 0)
		type = VPIPE;
	if (type != NONE)
		ft_dlstadd_back(tokens, ft_dlstnew(ft_new_token(type, NULL)));
	return (++mark);
}

static char	*tf_tokenize_quote(t_dlist **tokens, char *mark)
{
	char		qtype;
	char		*iter;
	char		*value;
	t_typtok	ttype;

	if (ft_strncmp(mark, "'", 1) == 0)
	{
		ttype = QUOTE;
		qtype = '\'';
	}
	else if (ft_strncmp(mark, "\"", 1) == 0)
	{
		ttype = DQUOTE;
		qtype = '"';
	}
	iter = mark + 1;
	while (*iter && *iter != qtype)
		++iter;
	value = ft_substr(mark, 0, iter - mark);
	ft_dlstadd_back(tokens, ft_dlstnew(ft_new_token(ttype, value)));
	return (iter);
}

void	ft_tokenize(t_dlist **tokens, char *user_input)
{
	char		*iter;

	iter = user_input;
	while (*iter)
	{
		if (*iter == '>' || *iter == '<' || *iter == '!' || *iter == '$'
			|| *iter == '|')
			iter = tf_tokenize_symbol(tokens, iter);
		else if (*iter == '\'' || *iter == '"')
			iter = tf_tokenize_quote(tokens, iter);
		else if (ft_isprint(*iter) && !ft_isspace(*iter))
			iter = tf_tokenize_word(tokens, iter);
		else
			++iter;
	}
}
