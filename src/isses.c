/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isses.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algarrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 13:34:47 by algarrig          #+#    #+#             */
/*   Updated: 2024/07/01 20:16:08 by algarrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/ft.h"

int	ft_isopp(int c)
{
	return (c == '>' || c == '<' || c == '$' || c == '|' || c == '\''
		|| c == '"' || c == '=');
}

int	ft_isnonquoteopp(int c)
{
	return (c == '>' || c == '<' || c == '!' || c == '$' || c == '|');
}

int	ft_isquoteopp(int c)
{
	return (c == '\'' || c == '"');
}

int	ft_isname(int c)
{
	return (ft_isalnum(c) || c == '_');
}

int ft_isass(int c)
{
	return (ft_isgraph(c) && (!ft_isopp(c) || c == '\'' || c == '"'
		|| c == '$'));
}
