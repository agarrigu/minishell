/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srodrigo <srodrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 17:52:05 by algarrig          #+#    #+#             */
/*   Updated: 2024/08/07 19:27:49 by srodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H
# include <stdbool.h>
# include "../libft/ft.h"
# include "command.h"

int		ft_pwd(char *argv[], t_dlist **environ);
int		ft_cd(char *argv[], t_dlist **environ);
int		ft_env(char *argv[], t_dlist **environ);
int		ft_echo(char *argv[], t_dlist **environ);
int		ft_unset(char *argv[], t_dlist **environ);
int		ft_export(char *argv[], t_dlist **environ);
int		ft_exit(char *argv[], t_dlist **environ, t_command *command);
bool	is_builtin(char *command);
int		exec_parent_builtin(t_command *command, t_dlist **environ);
int		execute_builtin(t_command command, t_dlist **environ);
void	execute_child_builtin(t_command command, t_dlist **environ);

#endif /* !BUILTINS_H */
