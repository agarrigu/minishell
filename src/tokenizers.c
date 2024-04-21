/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algarrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 21:02:10 by algarrig          #+#    #+#             */
/*   Updated: 2024/04/21 21:10:36 by algarrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/ft.h"
#include "isses.h"
#include "token.h"

char	*ft_tokenize_dless(t_dlist **tokens, char *mark)
{
	char	*iter;
	char	*value;

	iter = mark + 2;
	value = NULL;
	while (ft_isspace(*iter))
		++iter;
	mark = iter;
	while (!ft_isopp(*iter) && ft_isgraph(*iter))
		++iter;
	if (iter != mark)
		value = ft_substr(mark, 0, iter - mark);
	ft_dlstadd_back(tokens, ft_dlstnew(ft_new_token(DLESS, value)));
	return (iter);
}

char	*tf_tokenize_word(t_dlist **tokens, char *mark)
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

char	*tf_tokenize_symbol(t_dlist **tokens, char *mark)
{
	t_typtok	type;

	type = NONE;
	if (ft_strncmp(mark, ">>", 2) == 0 && ++mark)
		type = DGREAT;
	else if (ft_strncmp(mark, ">", 1) == 0)
		type = GREAT;
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

char	*tf_tokenize_quote(t_dlist **tokens, char *mark)
{
	char		qtype;
	char		*iter;
	char		*value;
	t_typtok	ttype;

	ttype = QUOTE;
	qtype = '\'';
	if ('"' == *mark)
	{
		ttype = DQUOTE;
		qtype = '"';
	}
	iter = mark + 1;
	while (*iter && *iter != qtype)
		++iter;
	if (!*iter)
		return (ft_dlstadd_back(tokens,
				ft_dlstnew(ft_new_token(ttype, NULL))), NULL);
	value = ft_substr(mark, 0, iter - mark);
	ft_dlstadd_back(tokens, ft_dlstnew(ft_new_token(ttype, value)));
	return (iter);
}
