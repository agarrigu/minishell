/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algarrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 19:13:32 by algarrig          #+#    #+#             */
/*   Updated: 2024/04/02 21:52:02 by algarrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../ft.h"

static size_t	tf_count_nmemb(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
			count++;
		while (*s && *s != c)
			s++;
	}
	return (count);
}

static void	*tf_free_so_far(char **a, unsigned int i)
{
	while (i--)
		free(a[i]);
	free(a);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char			**split;
	unsigned int	i;
	size_t			nmemb;
	const char		*rp;

	nmemb = tf_count_nmemb(s, c);
	split = malloc((nmemb + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	split[nmemb] = NULL;
	i = 0;
	while (i < nmemb)
	{
		while (*s && *s == c)
			s++;
		rp = s + 1;
		while (*rp && *rp != c)
			rp++;
		split[i] = ft_substr(s, 0, rp - s);
		if (split[i] == NULL)
			return (tf_free_so_far(split, i));
		s = rp;
		i++;
	}
	return (split);
}
