/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_cleaner.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bob </var/mail/bob>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 21:00:03 by bob               #+#    #+#             */
/*   Updated: 2024/05/21 18:41:21 by bob              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../token.h"
#include <stdlib.h>

void	ft_token_cleaner(void *vptr)
{
	t_token	*token;

	if (!vptr)
		return ;
	token = (t_token *) vptr;
	token->value && (free((void *) token->value), 0);
	token && (free(token), 0);
}
