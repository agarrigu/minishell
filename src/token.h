/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algarrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 14:48:19 by algarrig          #+#    #+#             */
/*   Updated: 2024/04/21 17:47:21 by algarrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H
# include "../libft/ft.h"

typedef enum e_typtok
{
	GREAT,
	DGREAT,
	LESS,
	DLESS,
	DOLLAR,
	VPIPE,
	QUOTE,
	DQUOTE,
	WORD,
	HEREDOC,
	NONE,
}	t_typtok;

typedef struct s_token
{
	t_typtok	type;
	const char	*value;
}	t_token;

t_token	*ft_new_token(t_typtok type, const char *val);
t_token	*ft_has_token(t_dlist *tokens, t_typtok ttype);

#endif /* !TOKEN_H */
