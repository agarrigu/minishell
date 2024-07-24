/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bob <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 14:39:28 by bob               #+#    #+#             */
/*   Updated: 2024/07/24 21:32:08 by algarrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include "../../libft/ft.h"
#include "../cleaners.h"
#include "../builtins.h"

static t_dlist	*ft_get_first_token(t_dlist *dlst)
{
	while (dlst->prev)
		dlst = dlst->prev;
	return (dlst);
}

int	ft_exit(char *argv[], t_dlist **environ, t_command *command)
{
	int		ret;
	t_dlist	*temp;

	ret = 0;
	if (argv[1] && argv[2])
		return (ft_putstr_fd("exit: ", 2), E2BIG);
	if (argv[1] && !ft_stris(argv[1], &ft_isdigit))
		return (ft_putstr_fd("exit: ", 2), EINVAL);
	if (argv[1])
		ret = ft_atoi(argv[1]);
	printf("exit\n");
	ft_command_cleaner(command);
	ft_dlstclear(environ, ft_kvpr_cleaner);
	temp = ft_get_first_token(command->tokens);
	ft_dlstclear(&temp, ft_token_cleaner);
	exit(ret);
}
