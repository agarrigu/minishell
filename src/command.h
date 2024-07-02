/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srodrigo <srodrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 12:55:00 by srodrigo          #+#    #+#             */
/*   Updated: 2024/07/01 15:59:32 by srodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_H
# define COMMAND_H
# include "../libft/ft.h"
# include <sys/wait.h>
# include <stdbool.h>
# include "token.h"

typedef struct s_command
{
	t_dlist	*tokens;
	int		position;
	int		inpipe;
	int		outpipe[2];
	char	**argv;
	char	*filepath;
}	t_command;

void	init_command(t_command *command, t_dlist *tokens);
int		get_num_commands(t_dlist *tokens);
pid_t	execute_command(t_command *command, t_dlist **environ);
char	**get_arguments(t_dlist *tokens, t_dlist *environ);
int		get_num_arguments(t_dlist *tokens);
char	*find_command_path(t_dlist *environ, char *cmd);
char	**get_env_paths(t_dlist *environ);
void	close_if_fd(int fd);
t_dlist	*get_next_command(t_dlist *tokens);
char	*get_name_value(const char *name, t_dlist *environ);
char	*get_command(t_dlist *tokens, t_dlist *environ);
char	*get_argument_value(t_token *token, t_dlist *environ);
void	handle_redirections(t_dlist *tokens);
bool	is_expandable(const char *dqword);
char	*expand_dqword(const char *dqword, t_dlist *environ);
void	infile_redirection(t_token *token);
void	outfile_redirection(t_token *token);
void	outfile_appended_redirection(t_token *token);
void	heredoc_redirection(t_token *token);
void	expand_command(t_token *token, t_dlist *environ);

#endif /* !COMMAND_H */