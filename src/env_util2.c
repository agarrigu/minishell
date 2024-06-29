/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_util2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algarrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 18:28:46 by algarrig          #+#    #+#             */
/*   Updated: 2024/06/29 18:33:13 by algarrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../libft/ft.h"
#include "mstypes.h"

static int	tf_count_entries(t_dlist *lst)
{
	int	n;

	while (lst)
	{
		++n;
		lst = lst->next;
	}
	return (n);
}

void	ft_kvprtov(t_dlist *environ)
{
	int		n;
	char	**envp;

	
	envp = ft_calloc(sizeof(), tf_count_entries(environ) + 1)
	while (environ)
	{
	}
	return (envp);
}
