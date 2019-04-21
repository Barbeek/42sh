/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_move_right.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 16:29:51 by hben-yah          #+#    #+#             */
/*   Updated: 2019/02/14 00:19:48 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	tc_cursor_move_right(t_edl *edl)
{
	if (edl->cur->h > edl->ncol - 1)
		tputs(tgetstr("nd", NULL), 1, sh_putchar);
}
