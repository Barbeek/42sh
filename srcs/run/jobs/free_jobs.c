/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_jobs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndubouil <ndubouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 16:42:56 by ndubouil          #+#    #+#             */
/*   Updated: 2019/03/30 00:40:54 by aroblin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	free_jobs(void)
{
	t_data_jobs		*djobs;
	t_job			**tmp;
	t_job			*next;
	t_data			*data;

	data = get_data();
	djobs = get_data_jobs();
	tmp = &djobs->jobs;
	while (*tmp)
	{
		next = (*tmp)->next;
		astlist_del(&(*tmp)->ast);
		ft_jobdelone(tmp);
		*tmp = next;
	}
}

void	free_jobs_param(t_job **jobs)
{
	t_job			**tmp;
	t_job			*next;
	t_data_jobs		*djobs;

	djobs = get_data_jobs();
	tmp = jobs;
	while (*tmp)
	{
		next = (*tmp)->next;
		if (!get_job_by_id(&djobs->jobs, (*tmp)->id))
			astlist_del(&(*tmp)->ast);
		ft_jobdelone(tmp);
		*tmp = next;
	}
}
