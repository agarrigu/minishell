/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algarrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 14:48:19 by algarrig          #+#    #+#             */
/*   Updated: 2024/05/13 19:41:14 by algarrig         ###   ########.fr       */
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
	TKN_OPP_DOLLAR,
	TKN_OPP_VLINE,
	TKN_OPP_QUOTE,
	TKN_OPP_DQUOTE,
	TKN_WORD,
	TKN_QWORD,
	TKN_DQWORD,
	TKN_NAME,
	TKN_IO_HERE,
	TKN_IO_NUMBER,
	TKN_IN_NUMBER,
	TKN_OUT_NUMBER,
	TKN_NONE,
}	t_typtok;

typedef struct s_token
{
	t_typtok	type;
	const char	*value;
}	t_token;

t_token		*ft_new_token(t_typtok type, const char *val);
t_typtok	ft_last_typtok(t_dlist *tokens);
void		ft_addtkntolst(t_dlist **tokens, t_typtok type, void *data);

#endif /* !TOKEN_H */
