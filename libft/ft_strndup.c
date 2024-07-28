/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algarrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 18:51:21 by algarrig          #+#    #+#             */
/*   Updated: 2024/07/28 18:51:50 by algarrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft.h"

char	*ft_strndup(const char *s, size_t n)
{
	char	*dup;
	char	*iter;

	dup = malloc(n + 1);
	if (!dup)
		return (NULL);
	iter = dup;
	while (*s && n--)
		*iter++ = *s++;
	*iter = '\0';
	return (dup);
}
