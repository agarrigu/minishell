/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kvpr_cleaner.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bob </var/mail/bob>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 14:21:00 by bob               #+#    #+#             */
/*   Updated: 2024/06/04 18:19:40 by algarrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mstypes.h"
#include <stdlib.h>

void	ft_kvpr_cleaner(void *vptr)
{
	t_kvpr	*kvpr;

	if (!vptr)
		return ;
	kvpr = (t_kvpr *) vptr;
	free((void *) kvpr->key);
	free((void *) kvpr->val);
	free(kvpr);
}
