/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift_tab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 16:23:12 by hben-yah          #+#    #+#             */
/*   Updated: 2019/03/23 11:46:59 by pespalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	do_shift_tab(t_data *data)
{
	leave_select_mode(&data->edl, 1);
	data->edl.bef = data->edl.cur->prev;
	insert_car_to_editline(&data->edl, ' ');
	update_view(&data->edl);
}
