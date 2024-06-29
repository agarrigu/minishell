/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srodrigo <srodrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 12:55:00 by srodrigo          #+#    #+#             */
/*   Updated: 2024/06/29 13:16:53 by srodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_H
# define COMMAND_H
# include "../libft/ft.h"
# include <sys/wait.h>

typedef struct s_command
{
	t_dlist	*tokens;
	int		position;
	int		inpipe_read;
	int		outpipe[2];
	char	**argv;
	char	*filepath;
}	t_command;

void	init_command(t_command *command, t_dlist *tokens);
int		get_num_commands(t_dlist *tokens);
pid_t	execute_command(t_command *command, t_dlist *environ);
char	**get_arguments(t_dlist *tokens);
int		get_num_arguments(t_dlist *tokens);
char	*find_command_path(t_dlist *environ, char *cmd);
char	**get_env_paths(t_dlist *environ);
void	close_if_fd(int fd);
t_dlist	*get_next_command(t_dlist *tokens); // token;

#endif /* !COMMAND_H */