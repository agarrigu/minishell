/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_util.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srodrigo <srodrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 18:22:27 by algarrig          #+#    #+#             */
/*   Updated: 2024/07/24 17:27:04 by algarrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_UTIL_H
# define ENV_UTIL_H
# include "../libft/ft.h"
# include "mstypes.h"

char		**ft_kvprtov(t_dlist *environ);
void		*ft_envdup(t_dlist **environ, char **envp);
const char	*ft_get_val(t_dlist *lst, const char *key);
const char	*ft_parse_val(const char *str);
const char	*ft_parse_key(const char *str);
t_kvpr		*get_kvpr(t_dlist *environ);
const char	*get_kvpr_key(t_kvpr *kvpr);
const char	*get_kvpr_value(t_kvpr *kvpr);
void		ft_add_msls_to_env(t_dlist **environ, int last_stat);

#endif /* !ENV_UTIL_H */
