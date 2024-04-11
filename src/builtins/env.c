/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algarrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 18:41:17 by algarrig          #+#    #+#             */
/*   Updated: 2024/04/11 16:27:34 by algarrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../../libft/ft.h"
#include "../mstypes.h"

int	env(t_dlist *environ)
{
	t_kvpr	*kvpr;

	while (environ)
	{
		kvpr = (t_kvpr *) environ->data;
		printf("%s=%s\n", kvpr->key, kvpr->val);
		environ = environ->next;
	}
	return (0);
}
