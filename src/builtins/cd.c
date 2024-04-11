/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algarrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 18:22:20 by algarrig          #+#    #+#             */
/*   Updated: 2024/03/21 18:32:02 by algarrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	cd(const char *path)
{
	return (chdir(path));
}

#ifdef TEST

int	main(int argc, char **argv)
{
	int	ret;

	(void) argc;
	ret = cd(argv[1]);
	printf("%s\n", getcwd(NULL, 0));
	return (ret);
}

#endif /* TEST */
