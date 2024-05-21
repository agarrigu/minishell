/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bob </var/mail/bob>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 16:23:26 by bob               #+#    #+#             */
/*   Updated: 2024/05/13 21:18:22 by algarrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stddef.h>
#include "../libft/ft.h"
#include <readline/readline.h>

/**
 * NOTE(algarrig): very hacky but it works. for now.
 * TODO(algarrig): make it less hacky, here is what we need to do:
 *   - clear/ignore/free the current rl_line_buffer
 *   - jump to a new line
 *   - display prompt
 *   - ???
 *   - profit
 *
 * NOTE(algarrig): removed errno safety cos it seems uneeded for now.
 * easily reinstated:
 *	int	temp_error;
 *
 *	temp_error = errno;
 *	// all the suff
 *	errno = temp_error;
 **/
void	ft_signal_handler(int signum)
{
	if (signum == SIGINT)
	{
		rl_replace_line("", 0);
		printf("\n$>");
		rl_redisplay();
	}
}

void	ft_setup_signal_handling(void)
{
	struct sigaction	s_sigact_ignore;
	struct sigaction	s_sigact_handler;

	ft_bzero(&s_sigact_ignore, sizeof(s_sigact_ignore));
	ft_bzero(&s_sigact_handler, sizeof(s_sigact_handler));
	s_sigact_ignore.sa_handler = SIG_IGN;
	s_sigact_handler.sa_handler = &ft_signal_handler;
	sigaction(SIGQUIT, &s_sigact_ignore, NULL);
	sigaction(SIGINT, &s_sigact_handler, NULL);
}
