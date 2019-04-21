/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 16:32:29 by hben-yah          #+#    #+#             */
/*   Updated: 2019/02/20 14:47:31 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	do_end(t_data *data)
{
	t_car *last;

	leave_select_mode(&data->edl, 0);
	last = data->edl.last;
	data->edl.cur = last;
	tc_cursor_move(last->h, last->v);
}
