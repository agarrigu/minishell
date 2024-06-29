/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizers.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algarrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 21:02:17 by algarrig          #+#    #+#             */
/*   Updated: 2024/06/26 18:28:46 by algarrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZERS_H
# define TOKENIZERS_H
# include "../libft/ft.h"

const char	*ft_tokenize_dollar(t_dlist **tokens,	const char *mark);
const char	*ft_tokenize_io_here(t_dlist **tokens, const char *mark, int *err);
const char	*ft_tokenize_opperator(t_dlist **tokens, const char *mark);
const char	*ft_tokenize_quote(t_dlist **tokens, const char *mark);
const char	*ft_tokenize_dquote(t_dlist **tokens, const char *mark);
const char	*ft_tokenize_word(t_dlist **tokens, const char *mark);

#endif /* !TOKENIZERS_H */
