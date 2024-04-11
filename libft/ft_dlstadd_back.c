/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstadd_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algarrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 19:36:08 by algarrig          #+#    #+#             */
/*   Updated: 2024/04/09 15:01:11 by algarrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_dlstadd_back(t_dlist **lst, t_dlist *new)
{
	t_dlist	*iter;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	iter = ft_dlstlast(*lst);
	iter->next = new;
	new->prev = iter;
}
