/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstadd_cond.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algarrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 15:14:00 by algarrig          #+#    #+#             */
/*   Updated: 2024/04/09 19:58:00 by algarrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_dlstadd_cond(t_dlist **lst, t_dlist *nu, int (*cond)(void *, void *))
{
	t_dlist	*iter;

	iter = *lst;
	if (!*lst)
	{
		*lst = nu;
		return ;
	}
	while (iter)
	{
		if ((*cond)(nu->data, iter->data))
			break ;
		iter = iter->next;
	}
	if (!iter->next)
		return (ft_dlstadd_back(lst, nu));
	else if (!iter->prev)
		return (ft_dlstadd_front(lst, nu));
	nu->next = iter;
	iter->prev->next = nu;
	nu->prev = iter->prev;
	iter->prev = nu;
}
