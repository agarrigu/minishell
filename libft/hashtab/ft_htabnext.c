/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_htabnext.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bob </var/mail/bob>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 11:34:15 by bob               #+#    #+#             */
/*   Updated: 2024/04/09 13:14:17 by algarrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

t_htitem	ft_htabnext(t_htiter *iter)
{
	t_htitem	*tab_iter;

	if (iter->rindex == 0)
		return ((t_htitem){NULL, NULL});
	tab_iter = &iter->htab->tab[iter->index + 1];
	++iter->index;
	while (tab_iter->key == NULL)
	{
		++iter->index;
		++tab_iter;
	}
	--iter->rindex;
	iter->item = tab_iter;
	return (*tab_iter);
}
