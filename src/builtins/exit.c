/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bob <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 14:39:28 by bob               #+#    #+#             */
/*   Updated: 2024/07/23 20:48:17 by algarrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include "../../libft/ft.h"

int	ft_exit(char *argv[], t_dlist **environ)
{
	(void) environ;
	if (argv[1] && argv[2])
		return (ft_putstr_fd("exit: ", 2), E2BIG);
	if (!argv[1])
		exit (0);
	if (!ft_stris(argv[1], &ft_isdigit))
		return (ft_putstr_fd("exit: ", 2), EINVAL);
	printf("exit\n");
	exit(ft_atoi(argv[1]));
}
