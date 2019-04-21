/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift_down.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 16:23:12 by hben-yah          #+#    #+#             */
/*   Updated: 2019/02/20 14:47:10 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	do_shift_down(t_data *data)
{
	t_car	*cur;
	t_car	*next;

	cur = data->edl.cur;
	next = cur->next;
	leave_select_mode(&data->edl, 0);
	while (next->val && (next->h < cur->h || next->v < cur->v + 1))
		next = next->next;
	data->edl.cur = next;
	tc_cursor_move(next->h, next->v);
}
