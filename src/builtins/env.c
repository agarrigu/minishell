/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srodrigo <srodrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 18:41:17 by algarrig          #+#    #+#             */
/*   Updated: 2024/07/23 20:49:04 by algarrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../../libft/ft.h"
#include "../mstypes.h"

int	ft_env(char *argv[], t_dlist **environ)
{
	t_kvpr	*kvpr;
	t_dlist	*liter;

	(void) argv;
	liter = *environ;
	while (liter)
	{
		kvpr = (t_kvpr *) liter->data;
		printf("%s=%s\n", kvpr->key, kvpr->val);
		liter = liter->next;
	}
	return (0);
}
