/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alt_x.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 16:23:37 by hben-yah          #+#    #+#             */
/*   Updated: 2019/03/29 21:38:59 by aroblin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void	routine_car(t_car **car, t_car **cut, t_data *data)
{
	while ((*car)->val)
	{
		if ((*car)->selected)
		{
			if (*car == data->edl.cur)
				data->edl.cur = data->edl.cur->next;
			*cut = *car;
			(*car)->prev->next = (*car)->next;
			(*car)->next->prev = (*car)->prev;
			(*car)->next->h = (*car)->h;
			(*car)->next->v = (*car)->v;
			*car = (*car)->next;
			set_cars_positions(&data->edl, *car);
			(*cut)->next = data->edl.clip->prev->next;
			(*cut)->prev = data->edl.clip->prev;
			data->edl.clip->prev->next = *cut;
			data->edl.clip->prev = *cut;
		}
		else
			*car = (*car)->next;
	}
}

void		do_alt_x(t_data *data)
{
	t_car *car;
	t_car *cut;

	if (data->edl.select_mode)
	{
		clear_clip(&data->edl);
		car = data->edl.last->next;
		data->edl.bef = NULL;
		routine_car(&car, &cut, data);
		update_view(&data->edl);
		leave_select_mode(&data->edl, 0);
	}
}
