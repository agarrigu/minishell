/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srodrigo <srodrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 15:10:03 by algarrig          #+#    #+#             */
/*   Updated: 2024/06/30 13:08:26 by srodrigo         ###   ########.fr       */
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

int	ft_export(char *argv[], t_dlist **environ)
{
	t_kvpr	*nukvpr;
	t_dlist	*liter;
	t_kvpr	*kvpr;

	while (*++argv)
	{
		nukvpr = malloc(sizeof(*nukvpr));
		nukvpr->key = ft_parse_key(*argv);
		nukvpr->val = ft_parse_val(*argv);
		liter = *environ;
		if (!liter)
			return (ft_dlstadd_front(environ, ft_dlstnew(nukvpr)), 0);
		while (liter)
		{
			kvpr = (t_kvpr *) liter->data;
			if (ft_strcmp(nukvpr->key, kvpr->key) == 0)
				return (tf_change_val(kvpr, nukvpr), 0);
			if (ft_strcmp(nukvpr->key, kvpr->key) < 0)
				return (tf_insertkvpr(environ, liter, nukvpr), 0);
			liter = liter->next;
		}
		if (!liter)
			ft_dlstadd_back(environ, ft_dlstnew(nukvpr));
	}
	return (0);
}
