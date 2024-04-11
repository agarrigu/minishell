/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algarrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:32:52 by algarrig          #+#    #+#             */
/*   Updated: 2023/11/01 19:36:39 by algarrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*bdest;
	const char	*bsrc;

	bdest = dest;
	bsrc = src;
	if (src < dest)
	{
		while (n--)
			bdest[n] = bsrc[n];
	}
	else
	{
		while (n--)
			*bdest++ = *bsrc++;
	}
	return (dest);
}
