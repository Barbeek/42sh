/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_move_left.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 16:29:51 by hben-yah          #+#    #+#             */
/*   Updated: 2019/03/23 11:52:16 by pespalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

/*
** `bw'
** Flag whose presence says that `le' may be used in column zero
** to move to the last column of the preceding line. If this flag is
** not present, `le' should not be used in column zero.
*/

void	tc_cursor_move_left(t_edl *edl)
{
	if (edl->cur->h > 0)
		tputs(tgetstr("le", NULL), 1, sh_putchar);
}
