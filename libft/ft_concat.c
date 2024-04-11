/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algarrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 17:27:46 by algarrig          #+#    #+#             */
/*   Updated: 2024/02/29 20:52:45 by algarrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include "ft.h"

char	*ft_concat(int membs, const char *a, const char *b, ...)
{
	va_list	ap;
	char	*s;
	char	*temp;

	va_start(ap, b);
	s = ft_strjoin(a, b);
	--membs;
	while (--membs)
	{
		temp = s;
		s = ft_strjoin(s, va_arg(ap, char *));
		free(temp);
	}
	va_end(ap);
	return (s);
}
