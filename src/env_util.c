/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algarrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 16:53:54 by algarrig          #+#    #+#             */
/*   Updated: 2024/04/11 17:05:31 by algarrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../libft/ft.h"
#include "mstypes.h"

const char	*ft_parse_key(const char *str)
{
	char	*iter;

	iter = ft_strchr(str, '=');
	return (ft_substr(str, 0, iter - str));
}

const char	*ft_parse_val(const char *str)
{
	char	*iter;

	iter = ft_strchr(str, '=') + 1;
	return (ft_strdup(iter));
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
