/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algarrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:02:32 by algarrig          #+#    #+#             */
/*   Updated: 2023/11/14 16:30:04 by algarrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strchr(const char *s, int c)
{
	char	*find;

	find = (char *)s;
	while (*find && *find != c)
		find++;
	if (*find || c == '\0')
		return (find);
	return (NULL);
}
