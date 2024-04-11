/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algarrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:34:45 by algarrig          #+#    #+#             */
/*   Updated: 2024/01/05 15:45:21 by algarrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

static int	tf_countdigs(int n)
{
	int	count;

	if (!n)
		return (1);
	count = 0;
	while (n)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static int	tf_charabsmodpowten(int n, int exp)
{
	int	out;

	out = 1;
	while (exp--)
		out *= 10;
	out = (n / out) % 10;
	if (out < 0)
		out = -out;
	return (out + '0');
}

int	ft_printnbr(int n)
{
	int	digs;
	int	done;

	done = 0;
	digs = tf_countdigs(n);
	if (n < 0)
	{
		ft_printchar('-');
		done++;
	}
	while (digs--)
		done += ft_printchar(tf_charabsmodpowten(n, digs));
	return (done);
}
