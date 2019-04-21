/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_last_status.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndubouil <ndubouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 20:45:48 by ndubouil          #+#    #+#             */
/*   Updated: 2019/03/22 18:17:55 by aroblin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void		update_last_status(int status)
{
	t_data_jobs		*djobs;
	t_data			*data;

	data = get_data();
	djobs = get_data_jobs();
	if (status >= 0)
	{
		djobs->last_status = status;
		data->param.status = djobs->last_status;
		set_val_nbr(&data->spe, "?", djobs->last_status);
	}
}
