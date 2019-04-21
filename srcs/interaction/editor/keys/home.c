/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   home.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 16:22:48 by hben-yah          #+#    #+#             */
/*   Updated: 2019/02/20 14:47:08 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	do_home(t_data *data)
{
	t_car *first;

	leave_select_mode(&data->edl, 0);
	first = data->edl.last->next;
	data->edl.cur = first;
	tc_cursor_move(first->h, first->v);
}
