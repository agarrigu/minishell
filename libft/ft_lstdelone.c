/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algarrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 19:41:33 by algarrig          #+#    #+#             */
/*   Updated: 2024/04/03 14:59:00 by algarrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst->data)
		(*del)(lst->data);
	free(lst);
	lst = NULL;
}
