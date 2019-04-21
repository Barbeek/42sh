/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_job_by_id.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroblin <aroblin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 16:41:49 by aroblin           #+#    #+#             */
/*   Updated: 2019/03/08 15:37:50 by aroblin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

t_job		*get_job_by_id(t_job **jobs, int id)
{
	t_job	*first;
	t_job	*tmp;

	if (!jobs)
		return (NULL);
	first = *jobs;
	tmp = *jobs;
	while (tmp)
	{
		if (tmp->id == id)
		{
			*jobs = first;
			return (tmp);
		}
		tmp = tmp->next;
	}
	*jobs = first;
	return (NULL);
}
