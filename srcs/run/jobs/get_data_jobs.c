/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data_jobs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndubouil <ndubouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 17:37:59 by ndubouil          #+#    #+#             */
/*   Updated: 2019/03/10 22:57:54 by ndubouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

t_data_jobs		*get_data_jobs(void)
{
	static t_data_jobs *data;

	if (!data)
	{
		try_m(data = ft_memalloc(sizeof(t_data_jobs)));
		data->last_status = 0;
	}
	return (data);
}
