/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algarrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 20:35:56 by algarrig          #+#    #+#             */
/*   Updated: 2024/08/06 20:42:20 by algarrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../libft/ft.h"
#include "env_util.h"
#include "isses.h"

void	ft_actually_expand_name(char **buff, const char **word,
	t_dlist *environ)
{
	const char	*val;
	const char	*key;

	key = ++(*word);
	while (ft_isname(**word))
		(*word)++;
	key = ft_strndup(key, *word - key);
	val = ft_get_val(environ, key);
	if (val)
		while (*val)
			*(*buff)++ = *val++;
	free((void *)key);
}

char	*ft_actually_expand_name2(char *buff, t_dlist *environ)
{
	const char	*val;
	const char	*key;
	char		*iter;

	iter = buff + 1;
	while (ft_isname(*iter))
		++iter;
	key = ft_strndup(buff + 1, iter - (buff + 1));
	val = ft_get_val(environ, key);
	if (!val)
		ft_memmove(buff, iter, ft_strlen(buff));
	else
	{
		ft_memmove(buff + ft_strlen(val), iter, ft_strlen(buff));
		while (*val)
			*buff++ = *val++;
	}
	free((void *)key);
	return (buff);
}
