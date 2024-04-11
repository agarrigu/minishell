/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algarrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:42:08 by algarrig          #+#    #+#             */
/*   Updated: 2024/04/02 13:32:25 by algarrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../ft.h"

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	char	*sub;
	char	*sp;
	size_t	nullen;

	if (start >= ft_strlen(str) || len == 0)
		return (ft_calloc(1, 1));
	nullen = ft_strlen(str + start);
	if (nullen < len)
		len = nullen;
	sub = malloc(len + 1);
	if (!sub)
		return (NULL);
	sp = sub;
	str += start;
	while (len-- && *str)
		*sp++ = *str++;
	*sp = '\0';
	return (sub);
}
