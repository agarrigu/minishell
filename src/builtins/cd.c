/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srodrigo <srodrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 18:22:20 by algarrig          #+#    #+#             */
/*   Updated: 2024/07/27 16:26:10 by algarrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/ft.h"
#include "../env_util.h"
#include <stdio.h>
#include <unistd.h>
#include <errno.h>

/*
 * We can safetly assign argv[1] to path as we know there will at least be two
 * entries in argv: one for the command name and a null pointer;
 */
int	ft_cd(char *argv[], t_dlist **environ)
{
	const char	*path;
	int			ret;

	path = argv[1];
	if (path && argv[2])
		return (ft_putstr_fd("cd: Too many arguments\n", 2), E2BIG);
	if (!path)
		path = ft_get_val(*environ, "HOME");
	if (!path)
		return (ft_putstr_fd("cd: Not a valid path\n", 2), EINVAL);
	ret = chdir(path);
	if (ret == -1)
	{
		ret = errno;
		perror("cd");
	}
	return (ret);
}
