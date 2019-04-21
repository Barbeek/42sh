/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_move_down.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 16:29:51 by hben-yah          #+#    #+#             */
/*   Updated: 2019/02/14 00:19:34 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	tc_cursor_move_down(t_edl *edl)
{
	if (edl->cur->v > edl->nrow - 1)
		tputs(tgetstr("do", NULL), 1, sh_putchar);
}
