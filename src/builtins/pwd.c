/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algarrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 17:58:56 by algarrig          #+#    #+#             */
/*   Updated: 2024/06/29 18:19:19 by algarrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "../../libft/ft.h"

int	ft_pwd(char *argv[], t_dlist **environ)
{
	char	*cwd;

	(void) argv;
	(void) environ;
	cwd = getcwd(NULL, 0);
	if (NULL == cwd)
		exit(errno);
	printf("%s\n", cwd);
	free(cwd);
	exit(0);
}
