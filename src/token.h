/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algarrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 14:48:19 by algarrig          #+#    #+#             */
/*   Updated: 2024/04/11 15:10:02 by algarrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H

typedef enum e_typtok
{
	BANG,
	GREAT,
	DGREAT,
	LESS,
	DLESS,
	DOLLAR,
	VPIPE,
	QUOTE,
	DQUOTE,
	WORD,
	NONE,
}	t_typtok;

typedef struct s_token
{
	t_typtok	type;
	const char	*value;
}	t_token;

t_token	*ft_new_token(t_typtok type, const char *val);

#endif /* !TOKEN_H */
