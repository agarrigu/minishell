/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srodrigo <srodrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 12:50:33 by algarrig          #+#    #+#             */
/*   Updated: 2024/07/02 15:41:39 by srodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdbool.h>
#include "../../libft/ft.h"

static int	tf_isvalidflag(const char *s)
{
	while (*s && *s == 'n')
		++s;
	return (*s == '\0');
}

int	ft_echo(char *argv[], t_dlist **environ)
{
	bool	print_newline;

	(void) environ;
	print_newline = true;
	++argv;
	while (*argv)
	{
		if (argv[0][0] == '-' && tf_isvalidflag(&argv[0][1]))
		{
			print_newline = false;
			++argv;
		}
		else
			break ;
	}
	while (*argv)
	{
		if (*argv[0])
		{
			printf("%s", *argv);
			(void) (argv[1] && printf(" "));
		}
		++argv;
	}
	return ((void)(print_newline && printf("\n")), 0);
}
