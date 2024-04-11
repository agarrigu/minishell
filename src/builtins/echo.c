/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algarrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 12:50:33 by algarrig          #+#    #+#             */
/*   Updated: 2024/04/08 11:00:01 by bob              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdbool.h>
#include "../../libft/ft.h"

int	echo(int argc, char *const argv[])
{
	int		i;
	bool	print_newline;

	i = 1;
	print_newline = true;
	if (argc > 1 && ft_strncmp(argv[1], "-n", 2) == 0)
	{
		++i;
		print_newline = false;
	}
	while (i < argc)
	{
		printf("%s", argv[i]);
		if (i != argc - 1)
			printf(" ");
		++i;
	}
	if (print_newline)
		printf("\n");
	return (0);
}
