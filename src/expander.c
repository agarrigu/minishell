/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algarrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 18:25:52 by algarrig          #+#    #+#             */
/*   Updated: 2024/08/06 20:40:26 by algarrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../libft/ft.h"
#include "expander_util.h"
#include "cleaners.h"
#include "token.h"
#include "isses.h"

static char	*tf_remove_squote(char *buff)
{
	char	*endq;

	endq = ft_strchr(buff + 1, '\'');
	ft_memmove(buff, buff + 1, endq - buff - 1);
	ft_memmove(endq - 1, endq + 1, ft_strlen(endq) + 2);
	return (endq - 1);
}

static char	*tf_expand_and_remove_dquote(char *buff, t_dlist *environ)
{
	char	*iter;

	iter = buff + 1;
	while (*iter != '"')
	{
		if (*iter == '$' && ft_isname(iter[1]))
			iter = ft_actually_expand_name2(iter, environ);
		else
			++iter;
	}
	ft_memmove(buff, buff + 1, iter - buff - 1);
	ft_memmove(iter - 1, iter + 1, ft_strlen(iter) + 2);
	return (iter - 1);
}

static void	tf_wordsplit(char *buff, t_dlist **tokens, t_dlist *environ)
{
	char	*mark;

	mark = buff;
	while (*buff)
	{
		if (*buff == '"' && ft_strchr(buff + 1, '"'))
			buff = tf_expand_and_remove_dquote(buff, environ) - 1;
		else if (*buff == '\'' && ft_strchr(buff + 1, '\''))
			buff = tf_remove_squote(buff) - 1;
		else if (mark != buff && ft_isblank(*buff) && ft_isgraph(buff[-1]))
			ft_addtkntolst(tokens, TKN_WORD, ft_strndup(mark, buff - mark));
		else if (mark != buff && ft_isgraph(*buff) && ft_isgraph(buff[-1]))
			;
		else
			mark = buff;
		++buff;
	}
	if (mark != buff)
		ft_addtkntolst(tokens, TKN_WORD, ft_strndup(mark, buff - mark));
}

static void	tf_expand_name(char *buff, const char *word, t_dlist *environ)
{
	size_t	len;

	while (*word)
	{
		if (*word == '"' && ft_strchr(word + 1, '"'))
		{
			len = ft_strchr(word + 1, '"') + 1 - word;
			ft_memcpy(buff, word, len);
			word += len;
			buff += len;
		}
		else if (*word == '\'' && ft_strchr(word + 1, '\''))
		{
			len = ft_strchr(word + 1, '\'') + 1 - word;
			ft_memcpy(buff, word, len);
			word += len;
			buff += len;
		}
		else if (*word == '$' && ft_isname(word[1]))
			ft_actually_expand_name(&buff, &word, environ);
		else
			*buff++ = *word++;
	}
}

void	ft_expand(t_dlist **tokens, t_dlist *environ)
{
	t_dlist	*new;
	t_dlist	*iter;
	t_token	*token;
	char	buff[2 * 1024 * 1024];

	iter = *tokens;
	new = NULL;
	while (iter)
	{
		token = (t_token *)iter->data;
		if (token->type == TKN_WORD)
		{
			ft_bzero(buff, sizeof(buff));
			tf_expand_name(buff, token->value, environ);
			tf_wordsplit(buff, &new, environ);
		}
		else
			ft_addtkntolst(&new, token->type, NULL);
		iter = iter->next;
	}
	ft_dlstclear(tokens, &ft_token_cleaner);
	*tokens = new;
}
