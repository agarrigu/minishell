/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_htabnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algarrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 17:39:13 by algarrig          #+#    #+#             */
/*   Updated: 2024/04/04 17:35:51 by bob              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <stdlib.h>

t_htab	*ft_htabnew(void)
{
	t_htab	*htab;

	htab = malloc(sizeof(t_htab));
	if (!htab)
		return (NULL);
	htab->nmembs = 0;
	htab->capacity = HASHTAB_INIT_CAP;
	htab->tab = ft_calloc(htab->capacity, sizeof(t_htitem));
	if (!htab->tab)
		return (NULL);
	return (htab);
}
