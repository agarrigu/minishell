/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algarrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 14:55:31 by algarrig          #+#    #+#             */
/*   Updated: 2024/04/21 20:56:11 by algarrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline/readline.h"
#include "../libft/ft.h"
#include <stdlib.h>
#include "token.h"

static size_t	tf_mini_gettotlen(t_list *lst)
{
	size_t	len;

	len = 0;
	while (lst)
	{
		len += ft_strlen((char *) lst->data) + 1;
		lst = lst->next;
	}
	return (len);
}

static char	*tf_mini_gnl(t_list *lst)
{
	size_t	len;
	char	*line;
	char	*citera;
	char	*citerb;

	len = tf_mini_gettotlen(lst);
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

static t_token	*tf_hdloop(const char *delim)
{
	char	*user_input;
	t_list	*heredoc_lst;
	t_token	*token;

	heredoc_lst = NULL;
	while (42)
	{
		user_input = readline("heredoc>");
		if (!user_input || 0 == ft_strcmp(user_input, delim))
			break ;
		ft_lstadd_back(&heredoc_lst, ft_lstnew(user_input));
	}
	token = ft_new_token(HEREDOC, tf_mini_gnl(heredoc_lst));
	ft_lstclear(&heredoc_lst, &ft_clear_void);
	return (token);
}

int	ft_do_heredoc(t_dlist **tokens)
{
	t_dlist	*iter;
	t_token	*token;

	iter = *tokens;
	while (iter)
	{
		token = (t_token *) iter->data;
		if (token->type == DLESS && token->value)
			ft_dlstadd_back(tokens, ft_dlstnew(tf_hdloop(token->value)));
		iter = iter->next;
	}
	return (0);
}
