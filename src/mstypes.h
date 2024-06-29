/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mstypes.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srodrigo <srodrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 12:57:34 by algarrig          #+#    #+#             */
/*   Updated: 2024/06/29 21:25:51 by algarrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSTYPES_H
# define MSTYPES_H
# define MS_ERR_OK 0
# define MS_ERR_HEREDOC_INVDELIM 1
# define WRITE_END 1
# define READ_END 0

typedef struct s_keyval
{
	const char	*key;
	const char	*val;
}	t_kvpr;

#endif /* !MSTYPES_H */
