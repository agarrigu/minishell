/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algarrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 17:58:56 by algarrig          #+#    #+#             */
/*   Updated: 2024/05/28 13:49:19 by bob              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	pwd(void)
{
	char	*cwd;

	cwd = getcwd(NULL, 0);
	(void) printf("%s\n", cwd);
	free(cwd);
	return (0);
}
