/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrow_left.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 16:22:00 by hben-yah          #+#    #+#             */
/*   Updated: 2019/03/14 15:58:54 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	do_arrow_left(t_data *data)
{
	t_car *c;

	c = data->edl.cur->prev;
	while (c->selected && c->prev->val)
		c = c->prev;
	if (c->val)
	{
		data->edl.cur = c;
		tc_cursor_move(c->h, c->v);
	}
	leave_select_mode(&data->edl, 0);
}
