/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srodrigo <srodrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 15:10:03 by algarrig          #+#    #+#             */
/*   Updated: 2024/07/27 16:30:57 by algarrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdlib.h>
#include "../mstypes.h"
#include "../builtins.h"
#include "../env_util.h"
#include "../../libft/ft.h"
#include <string.h>

static void	tf_change_val(t_kvpr *old, t_kvpr *nu)
{
	free((void *) old->val);
	old->val = nu->val;
	free((void *) nu->key);
	nu->key = NULL;
	free(nu);
	nu = NULL;
}

static void	tf_insertkvpr(t_dlist **environ, t_dlist *lst, t_kvpr *nukvpr)
{
	t_dlist	*nulst;

	nulst = ft_dlstnew(nukvpr);
	nulst->prev = lst->prev;
	nulst->next = lst;
	if (!lst->prev)
		*environ = nulst;
	else
	{
		lst->prev->next = nulst;
		lst->prev = nulst;
	}
}

static void	tf_do_the_thing(t_dlist **environ, t_kvpr *new_kvpr)
{
	t_kvpr	*tmp_kvpr;
	t_dlist	*iter;

	iter = *environ;
	while (iter)
	{
		tmp_kvpr = (t_kvpr *) iter->data;
		if (ft_strcmp(new_kvpr->key, tmp_kvpr->key) == 0)
			return ((void) tf_change_val(tmp_kvpr, new_kvpr));
		if (ft_strcmp(new_kvpr->key, tmp_kvpr->key) < 0)
			return ((void) tf_insertkvpr(environ, iter, new_kvpr));
		iter = iter->next;
	}
	if (!iter)
		ft_dlstadd_back(environ, ft_dlstnew(new_kvpr));
}

static bool	is_valid_key(const char *str)
{
	if ((ft_isalpha(*str) || (*str == '_'))
		&& !ft_strchr(str, ' '))
		return (true);
	else
	{
		ft_putstr_fd("export ", 2);
		ft_putstr_fd((char *) str, 2);
		ft_putstr_fd(": Not a valid identifier", 2);
		ft_putchar_fd('\n', 2);
		return (false);
	}
}

int	ft_export(char *argv[], t_dlist **environ)
{
	t_kvpr		*new_kvpr;
	const char	*key;

	++argv;
	if (!*argv)
		return (ft_env(NULL, environ), 0);
	while (*argv)
	{
		if (**argv == '=')
			return (ft_putstr_fd("export: Not a valid identifier\n", 2),
				EINVAL);
		key = ft_parse_key(*argv);
		if (is_valid_key(key))
		{
			new_kvpr = malloc(sizeof(*new_kvpr));
			new_kvpr->key = key;
			new_kvpr->val = ft_parse_val(*argv);
			tf_do_the_thing(environ, new_kvpr);
		}
		else
			return (free((char *) key), EINVAL);
		++argv;
	}
	return (0);
}
