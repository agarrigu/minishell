/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ass_tab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algarrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 20:25:51 by algarrig          #+#    #+#             */
/*   Updated: 2024/04/02 18:55:03 by algarrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ass_tab.h"
#include "ft.h"

const char	*ft_get_value(t_kvpair *environ, const char *key)
{
	t_kvpair	*iter;

	iter = environ;
	while (iter)
	{
		if (ft_strcmp(iter->key, key) == 0)
			return (iter->val);
		iter = iter->next;
	}
	return (NULL);
}

int	ft_add_entry(t_kvpair **environ, const char *key, const char *value)
{
	t_kvpair	*new_pair;
	t_kvpair	*iter;

	new_pair = malloc(sizeof(*new_pair));
	new_pair->key = key;
	new_pair->val = value;
	new_pair->next = NULL;
	iter = *environ;
	if (iter == NULL)
		*environ = new_pair;
	else
	{
		while (iter->next)
			iter = iter->next;
		iter->next = new_pair;
	}
	return (0);
}

int	ft_mod_entry(t_kvpair *environ, const char *key, const char *new_val)
{
	t_kvpair	*iter;

	iter = environ;
	while (iter)
	{
		if (ft_strcmp(iter->key, key) == 0)
		{
			free((char *) iter->val);
			iter->val = new_val;
			return (0);
		}
		iter = iter->next;
	}
	return (-1);
}

/* I'm gonna blame all this ugly on Norminette (algarrig)*/
int	ft_del_entry(t_kvpair **environ, const char *key)
{
	t_kvpair	*iter;
	t_kvpair	*tdl;

	iter = *environ;
	tdl = NULL;
	if (ft_strcmp(iter->key, key) == 0)
		tdl = iter;
	else
	{
		while (iter->next)
		{
			if (ft_strcmp(iter->next->key, key) == 0)
			{
				tdl = iter->next;
				break ;
			}
			iter = iter->next;
		}
	}
	if (tdl)
	{
		iter->next = tdl->next;
		return (free((char *)tdl->key), free((char *)tdl->val), free(tdl), 0);
	}
	return (-1);
}

int	ft_clean_ass(t_kvpair *environ)
{
	t_kvpair	*iter;
	t_kvpair	*temp;

	iter = environ;
	while (iter)
	{
		temp = iter->next;
		free((char *)iter->key);
		free((char *)iter->val);
		free(iter);
		iter = temp;
	}
	return (0);
}
