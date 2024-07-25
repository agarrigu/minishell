/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bob <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 14:39:28 by bob               #+#    #+#             */
/*   Updated: 2024/07/25 18:18:39 by algarrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include "../../libft/ft.h"
#include "../cleaners.h"
#include "../builtins.h"

int	ft_exit(char *argv[], t_dlist **environ, t_command *command)
{
	int		ret;

	ret = 0;
	if (argv[1] && argv[2])
		return (ft_putstr_fd("exit: ", 2), E2BIG);
	if (argv[1] && !ft_stris(argv[1], &ft_isdigit))
		return (ft_putstr_fd("exit: ", 2), EINVAL);
	if (argv[1])
		ret = ft_atoi(argv[1]);
	printf("exit\n");
	ft_complete_cleaner(command, environ);
	exit(ret);
}
