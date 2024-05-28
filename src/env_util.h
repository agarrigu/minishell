/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_util.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algarrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 18:22:27 by algarrig          #+#    #+#             */
/*   Updated: 2024/05/28 13:30:47 by bob              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_UTIL_H
# define ENV_UTIL_H
# include "../libft/ft.h"

void		*ft_envdup(t_dlist **environ, char **envp);
const char	*ft_get_val(t_dlist *lst, const char *key);
const char	*ft_parse_val(const char *str);
const char	*ft_parse_key(const char *str);

#endif /* !ENV_UTIL_H */
