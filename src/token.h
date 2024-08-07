/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srodrigo <srodrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 14:48:19 by algarrig          #+#    #+#             */
/*   Updated: 2024/08/07 17:36:39 by srodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H
# include "../libft/ft.h"

typedef enum e_typtok
{
	TKN_OPP_GREAT,
	TKN_OPP_DGREAT,
	TKN_OPP_LESS,
	TKN_OPP_DLESS,
	TKN_OPP_VLINE,
	TKN_WORD,
	TKN_IO_HERE,
	TKN_NONE,
	TKN_CMD,
	TKN_ARG,
}	t_typtok;

typedef struct s_token
{
	t_typtok	type;
	const char	*value;
}	t_token;

t_token		*ft_new_token(t_typtok type, const char *val);
t_typtok	ft_last_typtok(t_dlist *tokens);
void		ft_addtkntolst(t_dlist **tokens, t_typtok type, void *data);
t_token		*get_token(t_dlist *tokens);
t_typtok	get_type(t_token *token);
void		set_type(t_token *token, t_typtok type);
const char	*get_value(t_token *token);
void		set_value(t_token *token, const char *value);
void		delete_node(t_dlist *tokens);
t_dlist		*ft_get_first_token(t_dlist *dlst);

#endif /* !TOKEN_H */
