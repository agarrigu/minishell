/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algarrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 18:05:19 by algarrig          #+#    #+#             */
/*   Updated: 2024/07/23 19:12:52 by algarrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_error.h"
#include "../libft/ft.h"
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static void	ft_print_ms_err(int ms_errno)
{
	char	*errs;

	if (ms_errno == MS_ERR_HEREDOC_INVDELIM)
		errs = "minishell: heredoc: Invalid heredoc delimiter.\n";
	ft_putstr_fd(errs, STDERR_FILENO);
}

void	handle_error(int ms_errno, pid_t pid)
{
	if (ms_errno < 4200)
	{
		errno = ms_errno;
		perror(NULL);
	}
	else
		ft_print_ms_err(ms_errno);
	if (0 == pid)
		exit (ms_errno);
}
