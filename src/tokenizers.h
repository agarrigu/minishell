/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizers.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algarrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 21:02:17 by algarrig          #+#    #+#             */
/*   Updated: 2024/05/15 21:06:37 by algarrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZERS_H
# define TOKENIZERS_H
# include "../libft/ft.h"

const char	*ft_tokenize_in_number(t_dlist **tokens, const char *mark);
const char	*ft_tokenize_out_number(t_dlist **tokens, const char *mark);
const char	*ft_tokenize_io_here(t_dlist **tokens, const char *mark, int *err);
const char	*ft_tokenize_opperator(t_dlist **tokens, const char *mark);
const char	*ft_tokenize_name(t_dlist **tokens,	const char *mark);
const char	*ft_tokenize_string(t_dlist **tokens, const char *mark);
const char	*ft_tokenize_word(t_dlist **tokens, const char *mark);
const char	*ft_tokenize_qword(t_dlist **tokens, const char *mark);
const char	*ft_tokenize_dqword(t_dlist **tokens, const char *mark);
const char	*ft_tokenize_ucquote(t_dlist **tokens, const char *mark);
const char	*ft_tokenize_ucdquote(t_dlist **tokens, const char *mark);
const char	*ft_tokenize_invdollar(t_dlist **tokens, const char *mark);

#endif /* !TOKENIZERS_H */
