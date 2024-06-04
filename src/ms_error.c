/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algarrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 14:10:43 by algarrig          #+#    #+#             */
/*   Updated: 2024/06/04 14:22:28 by algarrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_error.h"
#include <errno.h>
#include <stdio.h>

void	ft_handle_error(int ms_errno)
{
	char *s;

	if (ms_errno == MS_ERR_HEREDOC_INVDELIM)
		s = "heredoc: Invalid delimiter";
	if (errno != 0)
		perror(errno);
}
