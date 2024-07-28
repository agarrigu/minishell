/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_freer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algarrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 20:00:22 by algarrig          #+#    #+#             */
/*   Updated: 2024/07/28 18:50:59 by algarrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft.h"

char	*ft_strjoin_freer(char const *left, char const *right)
{
	char	*join;

	join = ft_strjoin(left, right);
	free((char *) right);
	return (join);
}
