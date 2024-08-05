/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algarrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 18:25:52 by algarrig          #+#    #+#             */
/*   Updated: 2024/08/05 21:27:15 by algarrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../libft/ft.h"
#include "env_util.h"
#include "token.h"
#include "isses.h"

/* static void	tf_wordsplit(t_dlist **tokens, const char *buff) */
/* { */
/* } */

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
		else if (*word == '"' && ft_strchr(word + 1, '"'))
		{
			len = ft_strchr(word + 1, '"') + 1 - word;
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

#include <stdio.h>

void	ft_expand(t_dlist **tokens, t_dlist *environ)
{
	t_dlist	*iter;
	char	buff[2 * 1024 * 1024];

	iter = *tokens;
	ft_bzero(buff, sizeof(buff));
	while (iter)
	{
		if (((t_token *)iter->data)->type == TKN_WORD)
		{
			tf_expand_name(buff, ((t_token *)iter->data)->value, environ);
			printf("%s\n", buff);
			/* tf_wordsplit(); */
			/* tf_expand_dquote_name(); */
			/* tf_remove_quotes(); */
		}
		iter = iter->next;
	}
}
