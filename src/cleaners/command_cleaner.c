/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_cleaner.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algarrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 18:20:52 by algarrig          #+#    #+#             */
/*   Updated: 2024/07/25 17:47:35 by algarrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/ft.h"
#include "../command.h"
#include <stdlib.h>

void	ft_command_cleaner(t_command *command)
{
	free(command->childs_pid);
	ft_freesplit(command->argv);
	free(command->filepath);
	command->childs_pid = NULL;
	command->argv = NULL;
	command->filepath = NULL;
}
