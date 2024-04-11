/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printubase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algarrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 16:02:15 by algarrig          #+#    #+#             */
/*   Updated: 2024/01/17 16:22:20 by algarrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

/* No over/underflow checks */
static unsigned long long	tf_unsafe_pow(int base, int exponent)
{
	unsigned long long	result;

	result = 1;
	while (exponent--)
		result *= base;
	return (result);
}

static int	tf_countdigs(unsigned long long n, int radix)
{
	int	count;

	if (!n)
		return (1);
	count = 0;
	while (n)
	{
		n /= radix;
		count++;
	}
	return (count);
}

static int	tf_get_index(unsigned long long n, int digs, int radix)
{
	unsigned long long	out;

	out = tf_unsafe_pow(radix, digs);
	if (out == 0)
		return (0);
	return ((n / out) % radix);
}

int	ft_printubase(unsigned long long n, const char *base)
{
	int	radix;
	int	digs;
	int	done;

	done = 0;
	radix = ft_strlen(base);
	digs = tf_countdigs(n, radix);
	while (digs--)
		done += ft_printchar(*(base + tf_get_index(n, digs, radix)));
	return (done);
}
