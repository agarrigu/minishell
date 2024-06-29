/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algarrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 12:50:33 by algarrig          #+#    #+#             */
/*   Updated: 2024/06/29 18:17:10 by algarrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
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
	char	**iter;

	(void) environ;
	print_newline = true;
	iter = argv;
	while (0 == ft_strncmp(*iter, "-n", 2))
	{
		if (tf_isvalidflag(&*iter[2]))
		{
			print_newline = false;
			++iter;
		}
	}
	while (*iter)
	{
		printf("%s", *iter);
		if (!iter[1])
			printf(" ");
		++iter;
	}
	if (print_newline)
		printf("\n");
	exit(0);
}
