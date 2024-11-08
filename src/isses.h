/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isses.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algarrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 13:33:34 by algarrig          #+#    #+#             */
/*   Updated: 2024/08/05 19:33:52 by algarrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ISSES_H
# define ISSES_H
# include <stdbool.h>

int		ft_isopp(int c);
int		ft_isname(int c);
int		ft_islongopp(const char *s);
bool	ft_is_opp_cand(int prev, int curr);

#endif /* !ISSES_H */
