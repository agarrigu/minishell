/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srodrigo <srodrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 12:55:00 by srodrigo          #+#    #+#             */
/*   Updated: 2024/07/25 21:14:19 by algarrig         ###   ########.fr       */
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
	pid_t	*childs_pid;
}	t_command;

bool	is_expandable(const char *dqword);
char	**get_arguments(t_dlist *tokens, t_dlist *environ);
char	**get_env_paths(t_dlist *environ);
char	*expand_ass(const char *assword, t_dlist *environ);
char	*expand_dqword(const char *dqword, t_dlist *environ);
char	*find_command_path(t_dlist **environ, t_command *cmd);
char	*get_argument_value(t_token *token, t_dlist *environ);
char	*get_command(t_dlist *tokens, t_dlist *environ);
char	*get_end_name(char *c);
char	*get_name_value(const char *name, t_dlist *environ);
char	*unquote(const char *quote);
int		get_num_arguments(t_dlist *tokens);
int		get_num_commands(t_dlist *tokens);
int		heredoc_redirection(t_token *token);
int		infile_redirection(t_token *token);
int		outfile_appended_redirection(t_token *token);
int		outfile_redirection(t_token *token);
pid_t	execute_command(t_command *command, t_dlist **environ);
t_dlist	*get_next_command(t_dlist *tokens);
void	check_command_path(t_command *cmd, t_dlist **environ);
void	close_if_fd(int fd);
void	execute_child_builtin(t_command command, t_dlist **environ);
void	expand_command(t_token *token, t_dlist *environ);
void	handle_redirections(t_dlist *tokens, t_command *cmd, t_dlist **environ);
void	init_command(t_command *command, t_dlist *tokens);

#endif /* !COMMAND_H */
