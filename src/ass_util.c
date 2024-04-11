/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ass_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algarrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 16:26:17 by algarrig          #+#    #+#             */
/*   Updated: 2024/04/02 17:20:55 by algarrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ass_tab.h"
#include <stddef.h>

size_t	ft_ass_size(t_kvpair *ass)
{
	size_t		membs;
	t_kvpair	*iter;

	membs = 0;
	iter = ass;
	while (iter)
	{
		iter = iter->next;
		++membs;
	}
	return (membs);
}
