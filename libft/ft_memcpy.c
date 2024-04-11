/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algarrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:28:43 by algarrig          #+#    #+#             */
/*   Updated: 2023/11/01 14:40:50 by algarrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*bdest;
	const char	*bsrc;

	bdest = dest;
	bsrc = src;
	while (n--)
		*bdest++ = *bsrc++;
	return (dest);
}
