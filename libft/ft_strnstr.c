/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algarrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 19:18:09 by algarrig          #+#    #+#             */
/*   Updated: 2023/11/14 20:56:39 by algarrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	len_little;

	if (!*little)
		return ((char *) big);
	len_little = ft_strlen(little);
	if (len < len_little)
		return (NULL);
	len -= len_little - 1;
	while (len-- && *(big + len_little - 1))
	{
		if (!ft_strncmp(big, little, len_little))
			return ((char *) big);
		big++;
	}
	return (NULL);
}
