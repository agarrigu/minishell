/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srodrigo <srodrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:53:00 by srodrigo          #+#    #+#             */
/*   Updated: 2024/08/08 00:05:54 by srodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RULES_H
# define RULES_H

# include <stdbool.h>
# include "../libft/ft.h"
# include "token.h"

bool	is_command_line(t_dlist **tokens);
bool	is_command(t_dlist **tokens);
bool	is_io_redir_list(t_dlist **tokens);
bool	is_io_redir(t_dlist **tokens);
bool	is_redir_operation(t_typtok tiktoker);
bool	is_command_name(t_dlist **tokens);
bool	is_args_list(t_dlist **tokens);
bool	is_arg(t_dlist **tokens);

#endif /* RULES_H */