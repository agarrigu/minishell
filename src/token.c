/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algarrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 14:47:57 by algarrig          #+#    #+#             */
/*   Updated: 2024/04/11 14:53:44 by algarrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include <stdlib.h>

t_token	*ft_new_token(t_typtok type, const char *value)
{
	t_token	*token;

	token = malloc(sizeof(*token));
	token->type = type;
	token->value = value;
	return (token);
}
