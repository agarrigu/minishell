/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_name.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srodrigo <srodrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 18:15:51 by srodrigo          #+#    #+#             */
/*   Updated: 2024/08/07 19:55:28 by srodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_NAME_H
# define COMMAND_NAME_H
# include "../libft/ft.h"

char	*get_command(t_dlist *tokens);
char	*find_command_path(t_dlist **environ, t_command *cmd);
char	**get_env_paths(t_dlist *environ);
void	check_command_path(t_command *cmd, t_dlist **environ);



#endif /* !COMMAND_NAME_H */
