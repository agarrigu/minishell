/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algarrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 14:39:07 by algarrig          #+#    #+#             */
/*   Updated: 2023/11/15 15:04:02 by algarrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft.h"

char	*ft_strjoin(char const *left, char const *right)
{
	size_t	size_left;
	size_t	size_right;
	char	*join;

	size_left = ft_strlen(left);
	size_right = ft_strlen(right);
	join = malloc(size_left + size_right + 1);
	if (!join)
		return (NULL);
	join[size_left + size_right] = '\0';
	while (size_right--)
		join[size_left + size_right] = right[size_right];
	while (size_left--)
		join[size_left] = left[size_left];
	return (join);
}
