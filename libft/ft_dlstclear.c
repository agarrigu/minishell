/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstclear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algarrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 20:10:15 by algarrig          #+#    #+#             */
/*   Updated: 2024/04/11 17:16:02 by algarrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <stdlib.h>

void	ft_dlstclear(t_dlist **lst, void (*del)(void *))
{
	t_dlist	*next;
	t_dlist	*iter;

	iter = *lst;
	while (iter)
	{
		next = iter->next;
		ft_dlstdelone(iter, del);
		iter = next;
	}
	*lst = NULL;
}
