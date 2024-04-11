/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algarrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:13:06 by algarrig          #+#    #+#             */
/*   Updated: 2023/11/30 00:30:06 by algarrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft.h"

static int	tf_isinset(int c, const char *set)
{
	while (*set)
		if (*set++ == c)
			return (1);
	return (0);
}

char	*ft_strtrim(char const *str, char const *set)
{
	char	*rp;

	if (*set == '\0')
		return (ft_strdup(str));
	while (*str && tf_isinset(*str, set))
		str++;
	if (*str == '\0')
		return (ft_calloc(1, 1));
	rp = ft_strchr(str, '\0') - 1;
	while (tf_isinset(*rp, set))
		rp--;
	return (ft_substr(str, 0, ++rp - str));
}
