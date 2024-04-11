/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_htabdelone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bob </var/mail/bob>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 16:05:01 by bob               #+#    #+#             */
/*   Updated: 2024/04/08 18:06:07 by bob              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <stdlib.h>

void	ft_htabdelone(t_htab *htab, const char *key)
{
	uint64_t	hash;
	void		*mark;
	size_t		index;

	hash = ft_hash_key(key);
	index = hash & (htab->capacity - 1);
	mark = NULL;
	while (htab->tab[index].key)
	{
		if (ft_strcmp(htab->tab[index].key, key) == 0
			&& (free((void *) htab->tab[index].key), 1))
			mark = &htab->tab[index];
		else if (mark && ft_hash_key(htab->tab[index].key) == hash)
		{
			ft_memcpy(mark, &htab->tab[index], sizeof(t_htitem));
			mark = &htab->tab[index];
		}
		++index;
		if (index >= htab->capacity)
			index = 0;
	}
}
