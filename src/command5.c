/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srodrigo <srodrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 12:28:20 by srodrigo          #+#    #+#             */
/*   Updated: 2024/07/02 16:32:04 by srodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"
#include "mstypes.h"
#include <unistd.h>
#include "token.h"
#include <stdlib.h>
#include <stdio.h>
#include "env_util.h"
#include "builtins.h"
#include <fcntl.h>
#include <errno.h>
#include <string.h>

char	*expand_ass(const char *assword, t_dlist *environ)
{
	char	*key;
	char	*assign;
	char	*value;

	assign = ft_strchr(assword, '=');
	key = malloc (sizeof(key) * (assign - assword + 1));
	ft_strlcpy(key, assword, (assign - assword + 1));
	if (*key == '\'')
		key = unquote(key);
	else if (is_expandable(key))
		key = expand_dqword(key, environ);
	value = ft_strdup(assign + 1);
	if (*value == '\'')
		key = unquote(value);
	else if (is_expandable(value))
		value = expand_dqword(value, environ);
	printf("The key: %s - The value: %s\n", key, value);
	return (ft_concat(3, key, "=", value));
}

char	*unquote(const char *quote)
{
	char	*unquoted;

	unquoted = malloc (sizeof(unquoted) * (ft_strlen(quote) - 1));
	ft_strlcpy(unquoted, quote + 1, (ft_strlen(quote) - 1));
	return (unquoted);
}

char	*get_end_name(char *c)
{
	while (*c)
	{
		if (*c == '$' || *c == ' ')
			return (c);
		c++;
	}
	return (NULL);
}

// NOTE: ft_putend_fl is giving linking problems!!! So I had to print the \n
// NOTE: check if the exit error is the correct
void	check_command_path(char *cmd)
{
	if (access(cmd, F_OK) != 0)
	{
		ft_putstr_fd("Error: ", 2);
		ft_putstr_fd(strerror(errno), 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd((char *) cmd, 2);
		ft_putchar_fd('\n', 2);
		exit(errno);
	}
	return ;
}
