/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algarrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 02:34:48 by algarrig          #+#    #+#             */
/*   Updated: 2024/07/02 02:38:43 by algarrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strnchr(const char *s, int c, size_t n)
{
	char	*find;

	find = (char *)s;
	while (*find && *find != c && n--)
		find++;
	if (*find || c == '\0')
		return (find);
	return (NULL);
}
