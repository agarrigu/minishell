/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_freel.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algarrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 18:48:21 by algarrig          #+#    #+#             */
/*   Updated: 2024/07/28 18:52:40 by algarrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft.h"

char	*ft_strjoin_freel(char const *left, char const *right)
{
	char	*join;

	join = ft_strjoin(left, right);
	free((char *)left);
	return (join);
}
