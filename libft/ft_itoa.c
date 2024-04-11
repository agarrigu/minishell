/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algarrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 22:57:03 by algarrig          #+#    #+#             */
/*   Updated: 2023/11/30 01:54:40 by algarrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static void	tf_setup(int n, int *digs, int *isneg)
{
	int	count;

	count = 1;
	if (n < 0)
	{
		count++;
		*isneg = 1;
	}
	n /= 10;
	while (n)
	{
		count++;
		n /= 10;
	}
	*digs = count;
}

static char	tf_absmodten(int n)
{
	n %= 10;
	if (n < 0)
		n = -n;
	return (n + '0');
}

char	*ft_itoa(int n)
{
	char	*asc;
	int		digs;
	int		isneg;

	isneg = 0;
	digs = 0;
	tf_setup(n, &digs, &isneg);
	asc = malloc(digs + 1);
	if (!asc)
		return (NULL);
	asc[digs] = '\0';
	while (digs--)
	{
		asc[digs] = tf_absmodten(n);
		n /= 10;
	}
	if (isneg)
		*asc = '-';
	return (asc);
}
