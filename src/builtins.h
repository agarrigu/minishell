/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algarrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 17:52:05 by algarrig          #+#    #+#             */
/*   Updated: 2024/04/09 20:05:05 by algarrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H
# include "../libft/ft.h"

int	pwd(void);
int	cd(const char *path);
int	env(t_dlist *environ);
int	echo(int argc, char **argv);
int	unset(t_dlist **environ, const char *key);
int	export(t_dlist **environ, const char *assign);

#endif /* !BUILTINS_H */
