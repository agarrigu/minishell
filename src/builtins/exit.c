/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bob <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 14:39:28 by bob               #+#    #+#             */
/*   Updated: 2024/06/29 18:07:17 by algarrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include "../../libft/ft.h"

/*
 * The return of the value must be done outside exit if we want uniform
 * behaviour in the builtins. This function does check that the arguments are
 * valid, but the calling function should exit with the given argument as the
 * status code.
 */
int	ft_exit(char *argv[], t_dlist **environ)
{
	(void) environ;
	if (argv[1] && argv[2])
		exit(E2BIG);
	if (!argv[1])
		exit(0);
	if (!ft_stris(argv[1], &ft_isdigit))
		exit(EINVAL);
	printf("exit\n");
	exit(0);
}
