/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_util2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srodrigo <srodrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 19:44:37 by srodrigo          #+#    #+#             */
/*   Updated: 2024/06/29 21:11:37 by srodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../libft/ft.h"
#include "mstypes.h"

t_kvpr	*get_kvpr(t_dlist *environ)
{
	return ((t_kvpr *) environ->data);
}

const char	*get_kvpr_key(t_kvpr *kvpr)
{
	return (kvpr->key);
}

const char	*get_kvpr_value(t_kvpr *kvpr)
{
	return (kvpr->val);
}

static int	tf_count_entries(t_dlist *lst)
{
	int	n;

	while (lst)
	{
		++n;
		lst = lst->next;
	}
	return (n);
}

char	**ft_kvprtov(t_dlist *environ)
{
	char	**envp;
	char	**iter;
	t_kvpr	*pair;

	envp = ft_calloc(tf_count_entries(environ) + 1, sizeof(*envp));
	iter = envp;
	while (environ)
	{
		pair = (t_kvpr *) environ->data;
		*iter++ = ft_concat(3, pair->key, "=", pair->val);
		environ = environ->next;
	}
	return (envp);
}
