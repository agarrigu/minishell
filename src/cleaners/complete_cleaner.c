/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complete_cleaner.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algarrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 18:10:14 by algarrig          #+#    #+#             */
/*   Updated: 2024/07/25 18:14:01 by algarrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cleaners.h"
#include "../../libft/ft.h"
#include "../token.h"

void	ft_complete_cleaner(t_command *cmd, t_dlist **environ)
{
	t_dlist	*temp;

	ft_command_cleaner(cmd);
	temp = ft_get_first_token(cmd->tokens);
	ft_dlstclear(&temp, ft_token_cleaner);
	ft_dlstclear(environ, ft_kvpr_cleaner);
}
