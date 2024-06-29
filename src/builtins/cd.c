/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algarrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 18:22:20 by algarrig          #+#    #+#             */
/*   Updated: 2024/06/29 18:17:41 by algarrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/ft.h"
#include "../env_util.h"
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

/*
 * We can safetly assign argv[1] to path as we know there will at least be two
 * entries in argv: one for the command name and a null pointer;
 */
int	ft_cd(char *argv[], t_dlist **environ)
{
	const char	*path;

	path = argv[1];
	if (path && argv[2])
		exit(E2BIG);
	if (!path)
		path = ft_get_val(*environ, "HOME");
	if (!path)
		exit(EINVAL);
	exit(chdir(path));
}
