/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algarrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 15:10:03 by algarrig          #+#    #+#             */
/*   Updated: 2024/05/28 13:43:44 by bob              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../mstypes.h"
#include "../env_util.h"
#include "../../libft/ft.h"

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

int	export(t_dlist **environ, const char *assign)
{
	t_kvpr	*nukvpr;
	t_dlist	*iter;
	t_kvpr	*kvpr;

	nukvpr = malloc(sizeof(*nukvpr));
	nukvpr->key = ft_parse_key(assign);
	nukvpr->val = ft_parse_val(assign);
	iter = *environ;
	if (!iter)
		return (ft_dlstadd_front(environ, ft_dlstnew(nukvpr)), 0);
	while (iter)
	{
		kvpr = (t_kvpr *) iter->data;
		if (ft_strcmp(nukvpr->key, kvpr->key) == 0)
			return (tf_change_val(kvpr, nukvpr), 0);
		if (ft_strcmp(nukvpr->key, kvpr->key) < 0)
			return (tf_insertkvpr(environ, iter, nukvpr), 0);
		iter = iter->next;
	}
	if (!iter)
		ft_dlstadd_back(environ, ft_dlstnew(nukvpr));
	return (0);
}
