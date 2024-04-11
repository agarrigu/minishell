/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ass_tab.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algarrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 20:01:12 by algarrig          #+#    #+#             */
/*   Updated: 2024/04/02 14:17:11 by algarrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASS_TAB_H
# define ASS_TAB_H

typedef struct s_kvpair
{
	const char		*key;
	const char		*val;
	struct s_kvpair	*next;
}	t_kvpair;

const char	*ft_get_value(t_kvpair *environ, const char *key);
int			ft_add_entry(t_kvpair **environ, const char *key, const char *val);
int			ft_mod_entry(t_kvpair *environ,
				const char *key, const char *new_val);
int			ft_del_entry(t_kvpair **environ, const char *key);
int			ft_clean_ass(t_kvpair *environ);

#endif /* !ASS_TAB_H */
