/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algarrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 20:39:18 by algarrig          #+#    #+#             */
/*   Updated: 2024/04/21 21:07:13 by algarrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/ft.h"
#include "tokenizers.h"
#include "isses.h"

void	ft_tokenize(t_dlist **tokens, char *user_input)
{
	char		*iter;

	iter = user_input;
	while (*iter)
	{
		if (0 == ft_strncmp("<<", iter, 2))
			iter = ft_tokenize_dless(tokens, iter);
		else if (ft_isnonquoteopp(*iter))
			iter = tf_tokenize_symbol(tokens, iter);
		else if (ft_isquoteopp(*iter))
			iter = tf_tokenize_quote(tokens, iter);
		else if (ft_isprint(*iter) && !ft_isspace(*iter))
			iter = tf_tokenize_word(tokens, iter);
		else
			++iter;
	}
}
