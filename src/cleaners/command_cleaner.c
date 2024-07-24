/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_cleaner.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algarrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 18:20:52 by algarrig          #+#    #+#             */
/*   Updated: 2024/07/24 18:24:07 by algarrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/ft.h"
#include "../command.h"
#include <stdlib.h>

void	ft_command_cleaner(t_command *command)
{
	ft_freesplit(command->argv);
	free(command->filepath);
}
