/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_htabclear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algarrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 17:52:38 by algarrig          #+#    #+#             */
/*   Updated: 2024/04/03 18:00:44 by algarrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <stdlib.h>

void	ft_htabclear(t_htab *tab)
{
	size_t	i;

	i = 0;
	while (i < tab->capacity)
		free((char *)tab->tab[i++].key);
	free(tab->tab);
	free(tab);
}
