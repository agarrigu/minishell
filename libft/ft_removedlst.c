/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_removedlst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bob </var/mail/bob>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 14:07:19 by bob               #+#    #+#             */
/*   Updated: 2024/04/11 17:03:16 by algarrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <stdlib.h>

void	ft_removedlst(t_dlist **lst, void (*del)(void *))
{
	t_dlist	*temp;

	temp = *lst;
	if (!temp)
		return ;
	if (!temp->prev)
		*lst = temp->next;
	if (temp->prev)
		temp->prev->next = temp->next;
	if (temp->next)
		temp->next->prev = temp->prev;
	(*del)(temp->data);
	free(temp);
}
