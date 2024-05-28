/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algarrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 15:18:19 by algarrig          #+#    #+#             */
/*   Updated: 2024/05/28 13:50:21 by bob              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/ft.h"
#include "../mstypes.h"
#include "../cleaners.h"

/**
 * According to POSIX, unset should not return error if the variable to unset
 * does not exist.
 **/
int	unset(t_dlist **environ, const char *key)
{
	t_dlist	*iter;
	t_kvpr	*kvpr;

	iter = *environ;
	while (iter)
	{
		kvpr = (t_kvpr *) iter->data;
		if (0 == ft_strcmp(kvpr->key, key))
			return (ft_removedlst(&iter, &ft_kvpr_cleaner), 0);
		iter = iter->next;
	}
	return (0);
}
