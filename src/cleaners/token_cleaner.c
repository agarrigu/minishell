/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_cleaner.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bob </var/mail/bob>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 21:00:03 by bob               #+#    #+#             */
/*   Updated: 2024/04/12 20:03:26 by bob              ###   ########.fr       */
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
	free(token);
}
