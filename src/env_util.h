/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_util.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srodrigo <srodrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 18:22:27 by algarrig          #+#    #+#             */
/*   Updated: 2024/06/29 13:19:47 by srodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_UTIL_H
# define ENV_UTIL_H
# include "../libft/ft.h"
# include "mstypes.h"

void		*ft_envdup(t_dlist **environ, char **envp);
const char	*ft_get_val(t_dlist *lst, const char *key);
const char	*ft_parse_val(const char *str);
const char	*ft_parse_key(const char *str);
t_kvpr		*get_kvpr(t_dlist *environ);
const char	*get_kvpr_key(t_kvpr *kvpr);
const char	*get_kvpr_value(t_kvpr *kvpr);

#endif /* !ENV_UTIL_H */
