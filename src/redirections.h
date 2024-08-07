/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srodrigo <srodrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 17:27:17 by srodrigo          #+#    #+#             */
/*   Updated: 2024/08/07 17:37:04 by srodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIRECTIONS_H
# define REDIRECTIONS_H
# include "command.h"
# include "../libft/ft.h"
# include "token.h"

void	handle_redirections(t_dlist *tokens, t_command *cmd, t_dlist **environ);
int		heredoc_redirection(t_token *token);
int		infile_redirection(t_token *token);
int		outfile_appended_redirection(t_token *token);
int		outfile_redirection(t_token *token);

#endif /* !REDIRECTIONS_H */
