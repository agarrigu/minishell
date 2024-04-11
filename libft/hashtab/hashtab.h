/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtab.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algarrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 14:31:23 by algarrig          #+#    #+#             */
/*   Updated: 2024/04/09 14:33:25 by algarrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASHTAB_H
# define HASHTAB_H
# include <stddef.h>
# include <stdint.h>
# define HASHTAB_INIT_CAP 16
# define FNV_OFFSET 14695981039346656037UL
# define FNV_PRIME 1099511628211UL

typedef struct s_htitem
{
	const char	*key;	
	void		*value;
}	t_htitem;

typedef struct s_htab
{
	t_htitem	*tab;
	size_t		capacity;
	size_t		nmembs;
}	t_htab;

uint64_t	ft_hash_key(const char *key);
t_htab		*ft_htabnew(void);
void		ft_htabclear(t_htab *tab);
void		*ft_htabgetval(t_htab *htab, const char *key);
const char	*ft_htabset(t_htab *htab, const char *key, void *value);

#endif /* !HASHTAB_H */
