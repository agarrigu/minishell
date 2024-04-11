/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kvpr_cleaner.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bob </var/mail/bob>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 14:21:00 by bob               #+#    #+#             */
/*   Updated: 2024/04/11 17:19:10 by algarrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mstypes.h"
#include <stdlib.h>

void	ft_kvpr_cleaner(void *vptr)
{
	t_kvpr	*kvpr;

	kvpr = (t_kvpr *) vptr;
	kvpr->key && (free((void *) kvpr->key), 0);
	kvpr->val && (free((void *) kvpr->val), 0);
	kvpr && (free(kvpr), 0);
}
