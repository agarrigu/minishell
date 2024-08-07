/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srodrigo <srodrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 17:46:32 by srodrigo          #+#    #+#             */
/*   Updated: 2024/08/07 19:52:24 by srodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARGUMENTS_H
# define ARGUMENTS_H
# include "../libft/ft.h"

char	**get_arguments(t_dlist *tokens);
int		get_num_arguments(t_dlist *tokens);

#endif /* !ARGUMENTS_H */