/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strvlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algarrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 20:51:10 by algarrig          #+#    #+#             */
/*   Updated: 2024/04/02 21:39:36 by algarrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strvlen(char **strv)
{
	size_t	nmembs;
	char	**iter;

	iter = strv;
	while (*iter)
	{
		++nmembs;
		++iter;
	}
	return (nmembs);
}
