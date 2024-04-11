/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algarrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 20:05:41 by algarrig          #+#    #+#             */
/*   Updated: 2023/12/01 15:31:42 by algarrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdint.h>
#include "ft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*alloc;
	size_t	total;

	if (!nmemb || !size)
		return (ft_calloc(1, 1));
	if (nmemb > SIZE_MAX / size)
		return (NULL);
	total = nmemb * size;
	alloc = malloc(total);
	if (!alloc)
		return (NULL);
	ft_bzero(alloc, total);
	return (alloc);
}
