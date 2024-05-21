/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstdellast.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algarrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 20:14:43 by algarrig          #+#    #+#             */
/*   Updated: 2024/05/15 18:32:51 by algarrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_dlstdellast(t_dlist **lst, void (*del)(void *))
{
	t_dlist	*iter;	

	iter = ft_dlstlast(*lst);
	if (iter && iter->prev)
		iter->prev->next = NULL;
	if (iter && iter->prev == NULL)
		*lst = NULL;
	if (iter)
		ft_dlstdelone(iter, del);
}
