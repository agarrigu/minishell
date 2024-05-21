/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_io_here.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bob </var/mail/bob>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:48:33 by bob               #+#    #+#             */
/*   Updated: 2024/05/21 18:55:51 by bob              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/ft.h"
#include "../isses.h"
#include "../mstypes.h"
#include "../heredoc.h"
#include <stdlib.h>

char	*ft_tokenize_io_here(t_dlist **tokens, char *mark, int *ms_errno)
{
	char	*iter;
	char	*delim;

	iter = mark;
	delim = NULL;
	while (ft_isspace(*iter))
		++iter;
	mark = iter;
	while (*iter && !ft_isopp(*iter) && ft_isgraph(*iter))
		++iter;
	if (iter == mark)
		return (NULL);
	delim = ft_substr(mark, 0, iter - mark);
	if (!delim)
		*ms_errno = MS_ERR_HEREDOC_INVDELIM;
	ft_do_heredoc(tokens, delim);
	delim && (free(delim), 0);
	return (iter);
}
