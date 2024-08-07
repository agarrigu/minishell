/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isses.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srodrigo <srodrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 13:34:47 by algarrig          #+#    #+#             */
/*   Updated: 2024/08/05 19:31:57 by algarrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "../libft/ft.h"

int	ft_isopp(int c)
{
	return (c == '>' || c == '<' || c == '|');
}

int	ft_isname(int c)
{
	return (c == '_' || ft_isalnum(c));
}

int	ft_islongopp(const char *s)
{
	return (ft_strncmp("<<", s, 2) == 0 || ft_strncmp(">>", s, 2) == 0);
}

bool	ft_is_opp_cand(int prev, int curr)
{
	if (prev == '<' && curr == '<')
		return (true);
	if (prev == '>' && curr == '>')
		return (true);
	return (false);
}
