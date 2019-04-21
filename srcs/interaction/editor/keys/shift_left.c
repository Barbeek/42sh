/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift_left.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 16:23:12 by hben-yah          #+#    #+#             */
/*   Updated: 2019/02/20 14:47:11 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	do_shift_left(t_data *data)
{
	t_car	*cur;

	cur = data->edl.cur;
	leave_select_mode(&data->edl, 0);
	while (ft_isspace(cur->prev->val))
		cur = cur->prev;
	while (cur->prev->val && !ft_isspace(cur->prev->val))
		cur = cur->prev;
	if (data->edl.cur != cur)
	{
		data->edl.cur = cur;
		tc_cursor_move(cur->h, cur->v);
	}
}
