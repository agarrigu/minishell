/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bob </var/mail/bob>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 16:23:26 by bob               #+#    #+#             */
/*   Updated: 2024/04/12 17:24:24 by bob              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <signal.h>
#include <stddef.h>
#include "../libft/ft.h"

void	ft_signal_handler(int sign)
{
	int	temp_error;

	(void) sign;
	temp_error = errno;
	if (sign == SIGINT)
		(void) "TODO(algarrig): get next prompt";
	errno = temp_error;
}

void	ft_setup_signal_handling(void)
{
	struct sigaction	s_sigact;

	ft_bzero(&s_sigact, sizeof(s_sigact));
	s_sigact.sa_handler = &ft_signal_handler;
	sigaction(SIGINT, &s_sigact, NULL);
	sigaction(SIGQUIT, &s_sigact, NULL);
}
