/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bob <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 14:39:28 by bob               #+#    #+#             */
/*   Updated: 2024/05/28 15:13:24 by bob              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include "../mstypes.h"
#include "../../libft/ft.h"

int	ft_builtin_exit(int argc, char **argv, int *lrs)
{
	if (argc > 2)
	{
		ft_putstr_fd("exit(builtin): ", 2);
		errno = E2BIG;
		return (E2BIG);
	}
	if (argc == 1)
		return (MS_ERR_OK);
	if (!ft_stris(argv[1], &ft_isdigit))
	{
		ft_putstr_fd("exit(builtin): ", 2);
		errno = EINVAL;
		return (EINVAL);
	}
	*lrs = ft_atoi(argv[1]);
	return (MS_ERR_OK);
}
