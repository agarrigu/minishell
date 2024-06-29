/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algarrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 17:52:05 by algarrig          #+#    #+#             */
/*   Updated: 2024/06/29 16:46:49 by algarrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H
# include "../libft/ft.h"

int	ft_pwd(char *argv[], t_dlist **environ);
int	ft_cd(char *argv[], t_dlist **environ);
int	ft_env(char *argv[], t_dlist **environ);
int	ft_echo(char *argv[], t_dlist **environ);
int	ft_unset(char *argv[], t_dlist **environ);
int	ft_export(char *argv[], t_dlist **environ);
int	ft_exit(char *argv[], t_dlist **environ);

#endif /* !BUILTINS_H */
