/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_htabgetval.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bob </var/mail/bob>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 16:52:21 by bob               #+#    #+#             */
/*   Updated: 2024/04/04 17:38:09 by bob              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	*ft_htabgetval(t_htab *htab, const char *key)
{
	uint64_t	hash;
	size_t		index;

	hash = ft_hash_key(key);
	index = hash & (htab->capacity - 1);
	while (htab->tab[index].key)
	{
		if (ft_strcmp(key, htab->tab[index].key) == 0)
		{
			return (htab->tab[--index].value);
		}
		++index;
		if (index >= htab->capacity)
			index = 0;
	}
	return (NULL);
}
