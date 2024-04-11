/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algarrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:22:54 by algarrig          #+#    #+#             */
/*   Updated: 2023/11/29 16:06:45 by algarrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char	*dp;
	size_t	len_dst;
	size_t	len_src;

	dp = dst;
	len_src = ft_strlen(src);
	while (size && *dp)
	{
		dp++;
		size--;
	}
	len_dst = dp - dst;
	if (!size--)
		return (len_dst + len_src);
	while (*src && size--)
		*dp++ = *src++;
	*dp = '\0';
	return (len_dst + len_src);
}
