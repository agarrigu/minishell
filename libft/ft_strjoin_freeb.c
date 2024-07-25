/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_freeb.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algarrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 20:00:22 by algarrig          #+#    #+#             */
/*   Updated: 2024/07/25 20:02:26 by algarrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft.h"

char	*ft_strjoin_freeb(char const *left, char const *right)
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
	free((char *) right);
	free((char *) left);
	return (join);
}
