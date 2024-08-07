/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srodrigo <srodrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 17:51:14 by srodrigo          #+#    #+#             */
/*   Updated: 2024/08/07 20:17:21 by srodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../libft/ft.h"
#include "token.h"
#include "arguments.h"

char	**get_arguments(t_dlist *tokens)
{
	int		narg;
	char	**argv;

	narg = get_num_arguments(tokens) + 1;
	argv = malloc (sizeof(*argv) * (narg + 1));
	argv[narg] = NULL;
	narg = 0;
	while (tokens)
	{
		if (get_type(get_token(tokens)) == TKN_CMD
			|| get_type(get_token(tokens)) == TKN_ARG)
		{
			argv[narg] = ft_strdup(get_value(get_token(tokens)));
			narg++;
		}
		if (get_type(get_token(tokens)) == TKN_OPP_VLINE)
			break ;
		tokens = tokens->next;
	}
	return (argv);
}

int	get_num_arguments(t_dlist *tokens)
{
	int	narg;

	narg = 0;
	while (tokens)
	{
		if (get_type(get_token(tokens)) == TKN_ARG)
			narg++;
		if (get_type(get_token(tokens)) == TKN_OPP_VLINE)
			break ;
		tokens = tokens->next;
	}
	return (narg);
}
