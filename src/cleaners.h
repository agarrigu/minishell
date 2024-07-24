/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaners.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bob </var/mail/bob>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 14:27:39 by bob               #+#    #+#             */
/*   Updated: 2024/07/24 18:41:48 by algarrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLEANERS_H
# define CLEANERS_H
# include "command.h"

void	ft_kvpr_cleaner(void *kvpr);
void	ft_token_cleaner(void *token);
void	ft_command_cleaner(t_command *command);

#endif /* !CLEANERS_H */
