/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_util.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algarrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 20:36:02 by algarrig          #+#    #+#             */
/*   Updated: 2024/08/08 13:07:45 by algarrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANDER_UTIL_H
# define EXPANDER_UTIL_H
# include "../libft/ft.h"

void	ft_actually_expand_name(char **buff, const char **word,
			t_dlist *environ);
char	*ft_actually_expand_name2(char *buff, t_dlist *environ);
void	ft_expand_last_status(char **buff, const char **word, t_dlist *environ);

#endif /* !EXPANDER_UTIL_H */
