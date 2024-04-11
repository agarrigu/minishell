/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algarrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:23:09 by algarrig          #+#    #+#             */
/*   Updated: 2024/01/17 16:21:50 by algarrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_printptr(void *p)
{
	int	done;

	done = 0;
	if (!p)
		return (ft_printstr("(nil)"));
	done += (ft_printstr("0x"));
	done += ft_printubase((unsigned long long) p, "0123456789abcdef");
	return (done);
}
