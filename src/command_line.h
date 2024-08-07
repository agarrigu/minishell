/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_line.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srodrigo <srodrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 18:05:11 by srodrigo          #+#    #+#             */
/*   Updated: 2024/08/07 19:16:52 by srodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_LINE_H
# define COMMAND_LINE_H
# include <sys/wait.h>
# include "../libft/ft.h"
# include "command.h"

void	init_command(t_command *command, t_dlist *tokens);
int		get_num_commands(t_dlist *tokens);
void	pipes_and_execute(int commands, t_command *command, t_dlist **environ);
void	close_if_fd(int fd);


#endif /* !COMMAND_LINE_H */
