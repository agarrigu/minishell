/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stris.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algarrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 13:44:12 by algarrig          #+#    #+#             */
/*   Updated: 2024/02/15 17:56:37 by algarrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_stris(char *s, int (*is)(int c))
{
	while (*s)
		if ((*is)(*s++) == 0)
			return (0);
	return (1);
}
