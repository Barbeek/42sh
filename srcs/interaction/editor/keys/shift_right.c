/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift_right.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 16:23:12 by hben-yah          #+#    #+#             */
/*   Updated: 2019/02/20 14:47:14 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	do_shift_right(t_data *data)
{
	t_car	*cur;

	cur = data->edl.cur;
	leave_select_mode(&data->edl, 0);
	while (cur->val && ft_isspace(cur->next->val))
		cur = cur->next;
	while (cur->val && !ft_isspace(cur->next->val))
		cur = cur->next;
	if (data->edl.cur != cur)
	{
		data->edl.cur = cur;
		tc_cursor_move(cur->h, cur->v);
	}
}
