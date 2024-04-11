/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algarrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 19:59:44 by algarrig          #+#    #+#             */
/*   Updated: 2024/03/21 20:18:35 by algarrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* TODO(algarrig): replace /home/user wiht ~ */
int	ft_print_prompt(void)
{
	char	*cwd;

	cwd = getcwd(NULL, 0);
	printf("%s@%s:%s", getenv("USER"), getenv("hostname"), cwd);
	free(cwd);
	return (0);
}
