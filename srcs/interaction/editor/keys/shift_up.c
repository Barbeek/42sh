/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 16:23:08 by hben-yah          #+#    #+#             */
/*   Updated: 2019/02/19 17:18:35 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	do_shift_up(t_data *data)
{
	t_car	*cur;
	t_car	*prev;

	cur = data->edl.cur;
	prev = cur->prev;
	leave_select_mode(&data->edl, 0);
	while (prev->prev->val && (prev->h > cur->h || prev->v > cur->v - 1))
		prev = prev->prev;
	data->edl.cur = prev;
	tc_cursor_move(prev->h, prev->v);
}
