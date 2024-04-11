/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algarrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 19:50:26 by algarrig          #+#    #+#             */
/*   Updated: 2024/02/16 15:17:08 by algarrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

long	ft_atol(const char *nptr)
{
	long	out;
	int		neg_flag;

	out = 0;
	neg_flag = 0;
	while (*nptr == ' ' || (*nptr >= '\t' && *nptr <= '\r'))
		nptr++;
	if (*nptr == '+')
		nptr++;
	else if (*nptr == '-')
	{
		nptr++;
		neg_flag++;
	}
	while (ft_isdigit(*nptr))
	{
		out *= 10;
		out += *nptr++ - '0';
	}
	if (neg_flag)
		out = -out;
	return (out);
}
