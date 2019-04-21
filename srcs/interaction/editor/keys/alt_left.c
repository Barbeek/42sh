/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alt_left.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 16:22:00 by hben-yah          #+#    #+#             */
/*   Updated: 2019/03/11 18:30:39 by aroblin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	do_alt_left(t_data *data)
{
	t_car *c;
	t_car *ori;

	enter_select_mode(&data->edl);
	ori = data->edl.select_ori;
	c = data->edl.cur->prev;
	if (c->val)
	{
		data->edl.cur = c;
		c->selected = (c->v < ori->v || (c->v == ori->v && c->h < ori->h));
		data->edl.bef = c;
		tc_cursor_move(c->h, c->v);
		update_view(&data->edl);
	}
}
