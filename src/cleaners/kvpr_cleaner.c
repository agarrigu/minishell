/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kvpr_cleaner.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bob </var/mail/bob>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 14:21:00 by bob               #+#    #+#             */
/*   Updated: 2024/04/12 20:03:06 by bob              ###   ########.fr       */
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
	kvpr->key && (free((void *) kvpr->key), 0);
	kvpr->val && (free((void *) kvpr->val), 0);
	free(kvpr);
}
