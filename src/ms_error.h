/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_error.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algarrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 18:06:11 by algarrig          #+#    #+#             */
/*   Updated: 2024/07/23 20:34:10 by algarrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MS_ERROR_H
# define MS_ERROR_H
# include <sys/wait.h>
# define MS_ERR_OK 4200
# define MS_ERR_HEREDOC_INVDELIM 4201

void	handle_error(int ms_errno);

#endif /* MS_ERROR_H */
