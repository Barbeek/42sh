/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 00:08:06 by hben-yah          #+#    #+#             */
/*   Updated: 2019/03/04 19:36:26 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	do_enter(t_data *data)
{
	leave_select_mode(&data->edl, 1);
	data->edl.enter = 1;
	data->edl.cur = data->edl.last;
	insert_car_to_editline(&data->edl, '\n');
}
