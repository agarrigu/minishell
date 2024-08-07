/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algarrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 14:55:31 by algarrig          #+#    #+#             */
/*   Updated: 2024/08/07 18:34:30 by algarrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>
#include "readline/readline.h"
#include "expander_util.h"
#include "../libft/ft.h"
#include "token.h"

static char	*tf_mini_gnl(t_list *lst)
{
	size_t	len;
	char	*line;
	char	*citera;
	char	*citerb;
	t_list	*liter;

	len = 0;
	liter = lst;
	while (liter)
	{
		len += ft_strlen((char *) liter->data) + 1;
		liter = liter->next;
	}
	line = malloc(len + 1);
	line[len] = '\0';
	citera = line;
	while (lst)
	{
		citerb = (char *) lst->data;
		ft_strcpy(citera, citerb);
		citera += ft_strlen(citerb);
		*citera++ = '\n';
		lst = lst->next;
	}
	return (line);
}

static const char	*tf_do_heredoc_and_free(const char *delim, const char *tf)
{
	char	*user_input;
	char	*heredoc;
	t_list	*heredoc_lst;

	heredoc_lst = NULL;
	while (42)
	{
		user_input = readline("heredoc>");
		if (!user_input || 0 == ft_strcmp(user_input, delim))
			break ;
		ft_lstadd_back(&heredoc_lst, ft_lstnew(user_input));
	}
	heredoc = tf_mini_gnl(heredoc_lst);
	ft_lstclear(&heredoc_lst, &ft_clear_void);
	free((void *)tf);
	delim = NULL;
	tf = NULL;
	return (heredoc);
}

static const char	*tf_remove_allquotes(const char *s)
{
	char	*iter;
	char	*delim;
	size_t	run;

	delim = ft_calloc(ft_strlen(s) + 1, 1);
	iter = delim;
	while (*s)
	{
		if ((*s == '\'' || *s == '"') && ft_strchr(s + 1, *s))
		{
			run = ft_strchr(s + 1, *s) - s - 1;
			ft_memcpy(iter, s + 1, run);
			ft_memcpy(iter + run, s + run + 2, ft_strlen(iter));
			s += run + 2;
			iter += run;
		}
		else
			*iter++ = *s++;
	}
	return (delim);
}

static const char	*tf_expand_and_free(const char *s, t_dlist *environ)
{
	char		buff[2 * 1024 * 1024];
	char		*biter;
	const char	*siter;

	ft_bzero(buff, sizeof(buff));
	siter = s;
	biter = buff;
	while (*siter)
	{
		if (*siter == '$')
			ft_actually_expand_name(&biter, &siter, environ);
		else
			*biter++ = *siter++;
	}
	free((void *)s);
	return (ft_strdup(buff));
}

void	ft_heredoc(t_dlist **tokens, t_dlist *environ)
{
	t_dlist		*iter;
	t_token		*token;
	bool		expand;
	const char	*delim;	

	iter = *tokens;
	expand = true;
	while (iter)
	{
		token = (t_token *)iter->data;
		if (token->type == TKN_WORD && iter->prev
			&& ((t_token *)iter->prev->data)->type == TKN_OPP_DLESS)
		{
			if (ft_strchr(token->value, '"') || ft_strchr(token->value, '\''))
				expand = false;
			delim = tf_remove_allquotes(token->value);
			token->type = TKN_IO_HERE;
			token->value = tf_do_heredoc_and_free(delim, token->value);
			free((void *)delim);
			if (expand)
				token->value = tf_expand_and_free(token->value, environ);
		}
		iter = iter->next;
	}
}
