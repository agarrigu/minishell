/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizers.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algarrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 21:02:17 by algarrig          #+#    #+#             */
/*   Updated: 2024/04/21 21:10:08 by algarrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZERS_H
# define TOKENIZERS_H
# include "../libft/ft.h"

char	*ft_tokenize_dless(t_dlist **tokens, char *mark);
char	*tf_tokenize_word(t_dlist **tokens, char *mark);
char	*tf_tokenize_symbol(t_dlist **tokens, char *mark);
char	*tf_tokenize_quote(t_dlist **tokens, char *mark);

#endif /* !TOKENIZERS_H */
