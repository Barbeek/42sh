/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alt_v.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 16:23:37 by hben-yah          #+#    #+#             */
/*   Updated: 2019/03/08 15:37:52 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	do_alt_v(t_data *data)
{
	t_car *car;

	car = data->edl.clip->next;
	if (car->val)
	{
		data->edl.bef = NULL;
		while (car->val)
		{
			insert_car_to_editline(&data->edl, car->val);
			car = car->next;
		}
		leave_select_mode(&data->edl, 0);
		update_view(&data->edl);
	}
}
