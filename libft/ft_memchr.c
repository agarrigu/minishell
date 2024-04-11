/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algarrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:55:33 by algarrig          #+#    #+#             */
/*   Updated: 2023/11/14 18:56:01 by algarrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*finger;

	finger = (unsigned char *)s;
	while (n--)
	{
		if (*finger == c)
			return (finger);
		finger++;
	}
	return (NULL);
}
