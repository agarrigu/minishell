/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_util2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srodrigo <srodrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 16:53:54 by algarrig          #+#    #+#             */
/*   Updated: 2024/06/29 13:24:41 by srodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../libft/ft.h"
#include "mstypes.h"

t_kvpr	*get_kvpr(t_dlist *environ)
{
	return ((t_kvpr *) environ->data);
}

const char	*get_kvpr_key(t_kvpr *kvpr)
{
	return (kvpr->key);
}

const char	*get_kvpr_value(t_kvpr *kvpr)
{
	return (kvpr->val);
}
