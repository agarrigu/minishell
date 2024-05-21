/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mstypes.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algarrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 12:57:34 by algarrig          #+#    #+#             */
/*   Updated: 2024/05/13 18:44:46 by algarrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSTYPES_H
# define MSTYPES_H
# define MS_ERR_OK 0
# define MS_ERR_HEREDOC_INVDELIM 1

typedef struct s_keyval
{
	const char	*key;
	const char	*val;
}	t_kvpr;

#endif /* !MSTYPES_H */
