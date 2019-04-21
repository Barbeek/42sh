/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_to_eol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 16:30:49 by hben-yah          #+#    #+#             */
/*   Updated: 2019/03/19 15:12:01 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	tc_clear_to_eol(t_edl *edl)
{
	char	*ce;
	int		i;

	if ((ce = tgetstr("ce", NULL)))
		tputs(ce, 1, sh_putchar);
	else
	{
		i = edl->cur->h;
		while (i < edl->ncol)
			write(FD_EDL, " ", 1);
	}
}
