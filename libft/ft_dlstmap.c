/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algarrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 10:38:44 by algarrig          #+#    #+#             */
/*   Updated: 2024/04/09 15:08:58 by algarrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

/**
 * TODO(al): With double linked list it should be possible to clean backwards.
 **/
t_dlist	*ft_dlstmap(t_dlist *lst, void *(*f)(void *), void (*del)(void *))
{
	t_dlist	*mapped;
	t_dlist	*iter;
	t_dlist	*new;

	iter = lst;
	mapped = NULL;
	while (iter)
	{
		new = ft_dlstnew((*f)(iter->data));
		if (!new)
		{
			ft_dlstclear(&mapped, del);
			return (NULL);
		}
		ft_dlstadd_back(&mapped, new);
		iter = iter->next;
	}
	return (mapped);
}
