/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_htabset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algarrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 19:37:54 by algarrig          #+#    #+#             */
/*   Updated: 2024/04/09 14:34:41 by algarrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashtab.h"
#include "../ft.h"
#include <stdlib.h>

static void	tf_htadditem(t_htitem *tab, size_t cap,
		const char *key, void *value)
{
	uint64_t	hash;
	size_t		index;

	hash = ft_hash_key(key);
	index = hash & (cap - 1);
	while (tab[index].key)
	{
		if (ft_strcmp(key, tab[index].key) == 0)
		{
			tab->value = value;
			return ;
		}
		++index;
		if (index >= cap)
			index = 0;
	}
	tab[index].key = key;
	tab[index].value = value;
}

static void	*tf_expand_htab(t_htab *htab)
{
	size_t		newcap;
	t_htitem	*newtab;
	size_t		i;

	newcap = htab->capacity * 2;
	if (newcap < htab->capacity)
		return (NULL);
	newtab = ft_calloc(newcap, sizeof(t_htitem));
	if (!newtab)
		return (NULL);
	i = 0;
	while (i < htab->capacity)
	{
		if (htab->tab[i].key)
			tf_htadditem(newtab, newcap, htab->tab[i].key, htab->tab[i].value);
		++i;
	}
	free(htab->tab);
	htab->tab = newtab;
	htab->capacity = newcap;
	return (newtab);
}

const char	*ft_htabset(t_htab *htab, const char *key, void *value)
{
	if (htab->nmembs > htab->capacity / 2 && !tf_expand_htab(htab))
		return (NULL);
	if (!ft_htabgetval(htab, key))
		key = ft_strdup(key);
	if (!key)
		return (NULL);
	tf_htadditem(htab->tab, htab->capacity, key, value);
	++htab->nmembs;
	return (key);
}
