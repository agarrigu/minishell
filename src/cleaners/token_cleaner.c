/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_cleaner.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bob </var/mail/bob>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 21:00:03 by bob               #+#    #+#             */
/*   Updated: 2024/04/11 17:18:19 by algarrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../token.h"
#include <stdlib.h>

void	ft_token_cleaner(void *vptr)
{
	t_token	*token;

	token = (t_token *) vptr;
	if (token && token->value)
		free((void *) token->value);
	if (token)
		free(token);
}
