/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freesplit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algarrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 13:18:23 by algarrig          #+#    #+#             */
/*   Updated: 2024/07/24 18:57:47 by algarrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_freesplit(char **split)
{
	char	**iter;

	iter = split;
	if (!iter)
		return ;
	while (*iter)
		free(*iter++);
	free(split);
}
