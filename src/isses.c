/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isses.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algarrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 13:34:47 by algarrig          #+#    #+#             */
/*   Updated: 2024/04/22 18:12:54 by bob              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/ft.h"

int	ft_isopp(int c)
{
	return (c == '>' || c == '<' || c == '!' || c == '$' || c == '|'
		|| c == '\'' || c == '"');
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