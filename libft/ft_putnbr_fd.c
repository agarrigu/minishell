/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algarrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:27:05 by algarrig          #+#    #+#             */
/*   Updated: 2023/11/16 17:01:37 by algarrig         ###   ########.fr       */
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

void	ft_putnbr_fd(int n, int fd)
{
	int	digs;

	digs = tf_countdigs(n);
	if (n < 0)
		ft_putchar_fd('-', fd);
	while (digs--)
		ft_putchar_fd(tf_charabsmodpowten(n, digs), fd);
}
