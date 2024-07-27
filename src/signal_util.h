/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_util.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bob </var/mail/bob>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 16:23:47 by bob               #+#    #+#             */
/*   Updated: 2024/07/27 17:02:10 by algarrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNAL_UTIL_H
# define SIGNAL_UTIL_H
# include <signal.h>

void	ft_setup_signal_handling(void);
void	ft_ignore_sigint(void);
void	ft_unignore_sigint(void);

#endif /* !SIGNAL_UTIL_H */
