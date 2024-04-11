/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_htabiter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bob </var/mail/bob>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 15:22:52 by bob               #+#    #+#             */
/*   Updated: 2024/04/09 13:15:28 by algarrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

/**
 * TODO(algarrig): See how many brakets you can omit in line 11
**/
t_htiter	*ft_htabiter(t_htiter *iter, t_htab *htab)
{
	t_htitem	*tab_iter;
	size_t		index;
	size_t		cap;

	tab_iter = htab->tab;
	cap = htab->capacity;
	index = 0;
	while (!tab_iter->key && cap--)
	{
		++tab_iter;
		++index;
	}
	if (cap == 0)
	{
		iter = NULL;
		return (NULL);
	}
	iter->index = index;
	iter->rindex = htab->nmembs - 1;
	iter->htab = htab;
	iter->item = tab_iter;
	return (iter);
}
