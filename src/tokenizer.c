/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bob </var/mail/bob>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 21:03:03 by bob               #+#    #+#             */
/*   Updated: 2024/04/11 15:56:07 by algarrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/ft.h"
#include <stdlib.h>
#include "token.h"

int	ft_isvalidword(char c)
{
	return (ft_isalnum(c) || c == '.' || c == '_' || c == '-' || c == '/');
}

char	*ft_tokenize_char(t_dlist **tokens, char *mark)
{
	char	*iter;
	char	*value;

	iter = mark;
	while (*iter && ft_isvalidword(*iter))
		++iter;
	value = ft_substr(mark, 0, iter - mark);
	ft_dlstadd_back(tokens, ft_dlstnew(ft_new_token(WORD, value)));
	return (iter);
}

char	*ft_tokenize_symbol(t_dlist **tokens, char *mark)
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
	else if (ft_strncmp(mark, "'", 1) == 0)
		type = QUOTE;
	else if (ft_strncmp(mark, "\"", 1) == 0)
		type = DQUOTE;
	if (type != NONE)
		ft_dlstadd_back(tokens, ft_dlstnew(ft_new_token(type, NULL)));
	return (++mark);
}

void	ft_tokenize(t_dlist **tokens, char *user_input)
{
	char		*iter;

	iter = user_input;
	while (*iter)
	{
		if (ft_isvalidword(*iter))
			iter = ft_tokenize_char(tokens, iter);
		else if (*iter == '>' || *iter == '<' || *iter == '!' || *iter == '$'
			|| *iter == '|' || *iter == '\'' || *iter == '"')
			iter = ft_tokenize_symbol(tokens, iter);
		else
			++iter;
	}
}
