/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srodrigo <srodrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 12:55:00 by srodrigo          #+#    #+#             */
/*   Updated: 2024/08/07 19:43:58 by srodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_H
# define COMMAND_H
# include <sys/wait.h>
# include "../libft/ft.h"

typedef struct s_command
{
	t_dlist	*tokens;
	int		position;
	int		inpipe;
	int		outpipe[2];
	char	**argv;
	char	*filepath;
	pid_t	*childs_pid;
}	t_command;

pid_t	execute_command(t_command *command, t_dlist **environ);
t_dlist	*get_next_command(t_dlist *tokens);

#endif /* !COMMAND_H */
