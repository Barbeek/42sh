/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backspace.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 16:22:00 by hben-yah          #+#    #+#             */
/*   Updated: 2019/03/02 18:40:15 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	do_backspace(t_data *data)
{
	t_car *car;

	car = data->edl.cur->prev;
	data->edl.bef = car->prev;
	delete_car(&data->edl, car);
	update_view(&data->edl);
}
