/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algarrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:38:14 by algarrig          #+#    #+#             */
/*   Updated: 2023/11/16 14:49:10 by algarrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft.h"

/* TODO: test */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*mapped;
	unsigned int	ind;

	ind = ft_strlen(s);
	mapped = malloc(ind + 1);
	if (!mapped)
		return (NULL);
	mapped[ind] = '\0';
	while (ind--)
		mapped[ind] = (*f)(ind, s[ind]);
	return (mapped);
}
