/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algarrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 19:42:37 by algarrig          #+#    #+#             */
/*   Updated: 2024/04/03 14:35:37 by algarrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <stdarg.h>

static int	tf_format_put(char type, va_list arg)
{
	int	done;

	done = 0;
	if (type == '%')
		done = ft_printchar('%');
	else if (type == 'c')
		done = ft_printchar(va_arg(arg, unsigned int));
	else if (type == 's')
		done = ft_printstr(va_arg(arg, char *));
	else if (type == 'd' || type == 'i')
		done = ft_printnbr(va_arg(arg, int));
	else if (type == 'u')
		done = ft_printubase(va_arg(arg, unsigned int),
				"0123456789");
	else if (type == 'x')
		done = ft_printubase(va_arg(arg, unsigned int),
				"0123456789abcdef");
	else if (type == 'X')
		done = ft_printubase(va_arg(arg, unsigned int),
				"0123456789ABCDEF");
	else if (type == 'p')
		done = ft_printptr(va_arg(arg, void *));
	return (done);
}

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	int		done;

	va_start(arg, str);
	done = 0;
	while (*str)
	{
		if (*str == '%' && ft_strchr("%Xcdispux", str[1]))
			done += tf_format_put(*++str, arg);
		else
			done += ft_printchar(*str);
		str++;
	}
	va_end(arg);
	return (done);
}
