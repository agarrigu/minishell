/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algarrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 18:22:20 by algarrig          #+#    #+#             */
/*   Updated: 2024/05/28 14:46:01 by bob              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/ft.h"
#include "../env_util.h"
#include <unistd.h>
#include <errno.h>

/**
 * NOTE(algarrig): A ver, no es lo mas elegante pero puede funcionar
 */
int	cd(t_dlist *environ, const char *path)
{
	if (!path)
		path = ft_get_val(environ, "HOME");
	if (!path)
	{
		ft_putstr_fd("cd(builtin): ", 2);
		errno = EINVAL;
		return (EINVAL);
	}
	return (chdir(path));
}
