/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_util2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algarrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 18:28:46 by algarrig          #+#    #+#             */
/*   Updated: 2024/06/29 18:51:37 by algarrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/ft.h"
#include "mstypes.h"

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
		pair = (t_kvpr*) environ->data;
		*iter++ = ft_concat(3, pair->key, "=", pair->val);
		environ = environ->next;
	}
	return (envp);
}
