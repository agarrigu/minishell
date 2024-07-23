/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srodrigo <srodrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 15:18:19 by algarrig          #+#    #+#             */
/*   Updated: 2024/07/23 20:45:28 by algarrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/ft.h"
#include "../mstypes.h"
#include "../cleaners.h"

/**
 * According to POSIX, unset should not return error if the variable to unset
 * does not exist.
 **/
int	ft_unset(char *argv[], t_dlist **environ)
{
	t_dlist	*liter;
	char	**viter;
	t_kvpr	*kvpr;

	viter = argv + 1;
	if (!viter[0])
		return (0);
	while (*viter)
	{
		liter = *environ;
		while (liter)
		{
			kvpr = (t_kvpr *) liter->data;
			if (0 == ft_strcmp(kvpr->key, *viter))
			{
				ft_removedlst(&liter, &ft_kvpr_cleaner);
				break ;
			}
			liter = liter->next;
		}
		++viter;
	}
	return (0);
}
