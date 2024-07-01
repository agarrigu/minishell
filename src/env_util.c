/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srodrigo <srodrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 16:53:54 by algarrig          #+#    #+#             */
/*   Updated: 2024/07/01 18:12:46 by algarrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../libft/ft.h"
#include "mstypes.h"

const char	*ft_parse_key(const char *str)
{
	char	*iter;

	iter = ft_strchrnul(str, '=');
	return (ft_substr(str, 0, iter - str));
}

const char	*ft_parse_val(const char *str)
{
	char	*iter;

	iter = ft_strchr(str, '=');
	if (iter)
		return (ft_strdup(iter + 1));
	else
		return (NULL);
}

const char	*ft_get_val(t_dlist *lst, const char *key)
{
	t_kvpr	*kvpr;

	while (lst)
	{
		kvpr = (t_kvpr *) lst->data;
		if (0 == ft_strcmp(kvpr->key, key))
			return (kvpr->val);
		lst = lst->next;
	}
	return (NULL);
}

/**
 * NOTE(algarrig): We will assume that all entries have a '=' char
 **/
void	ft_envdup(t_dlist **environ, char **envp)
{
	char	**iter;
	t_kvpr	*kvpr;

	iter = envp;
	while (*iter)
	{
		kvpr = malloc(sizeof(*kvpr));
		kvpr->key = ft_parse_key(*iter);
		kvpr->val = ft_parse_val(*iter);
		ft_dlstadd_back(environ, ft_dlstnew(kvpr));
		++iter;
	}
}
