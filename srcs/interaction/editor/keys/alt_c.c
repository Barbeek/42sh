/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alt_c.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 16:23:37 by hben-yah          #+#    #+#             */
/*   Updated: 2019/03/14 18:37:24 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	do_alt_c(t_data *data)
{
	t_car *car;
	t_car *cpy;

	if (data->edl.select_mode)
	{
		clear_clip(&data->edl);
		car = data->edl.last->next;
		while (car->val)
		{
			if (car->selected)
			{
				if (!(cpy = car_dup(car)))
					return ;
				cpy->next = data->edl.clip->prev->next;
				cpy->prev = data->edl.clip->prev;
				data->edl.clip->prev->next = cpy;
				data->edl.clip->prev = cpy;
			}
			car = car->next;
		}
	}
}
