/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algarrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 18:25:52 by algarrig          #+#    #+#             */
/*   Updated: 2024/08/06 17:22:37 by algarrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../libft/ft.h"
#include "env_util.h"
#include "cleaners.h"
#include "token.h"
#include "isses.h"

static void	tf_wordsplit(t_dlist **tokens, const char *buff)
{
	const char	*mark;

	mark = buff;
	while (*buff)
	{
		if (*buff == '"' && ft_strchr(buff + 1, '"'))
			buff = ft_strchr(buff + 1, '"');
		else if (*buff == '\'' && ft_strchr(buff + 1, '\''))
			buff = ft_strchr(buff + 1, '\'');
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

static void	tf_actually_expand_name(char **buff, const char **word,
	t_dlist *environ)
{
	const char	*val;
	const char	*key;

	key = ++(*word);
	while (ft_isname(**word))
		(*word)++;
	key = ft_strndup(key, *word - key);
	val = ft_get_val(environ, key);
	if (val)
		while (*val)
			*(*buff)++ = *val++;
	free((void *)key);
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
			tf_actually_expand_name(&buff, &word, environ);
		else
			*buff++ = *word++;
	}
}

#include "helpers.h"

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
			tf_wordsplit(&new, buff);
			/* tf_expand_dquote_name(); */
			/* tf_remove_quotes(); */
		}
		else
			ft_addtkntolst(&new, token->type, NULL);
		iter = iter->next;
	}
	print_tokens(*tokens);
	print_tokens(new);
	ft_dlstclear(tokens, &ft_token_cleaner);
	*tokens = new;
}
