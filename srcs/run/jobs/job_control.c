/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   job_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroblin <aroblin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 03:02:06 by aroblin           #+#    #+#             */
/*   Updated: 2019/03/08 16:22:00 by ndubouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void		change_id_in_data(t_job *j)
{
	t_data_jobs	*djobs;

	djobs = get_data_jobs();
	if (j->next)
	{
		if (!is_job_ctrl_bt(j->ast))
		{
			if (djobs->current_id - 1)
				djobs->old_current_id = djobs->current_id - 1;
			djobs->current_id = j->next->id;
		}
	}
	else
	{
		djobs->current_id = djobs->old_current_id;
		if (djobs->current_id - 1)
			djobs->old_current_id = djobs->current_id - 1;
	}
}

void			clean_finish_jobs(void)
{
	t_job		*j;
	t_job		*jnext;
	t_data_jobs	*djobs;

	djobs = get_data_jobs();
	update_status();
	jnext = NULL;
	j = djobs->jobs;
	while (j != NULL)
	{
		if (job_is_completed(j))
		{
			change_id_in_data(j);
			jnext = j->next;
			remove_one_job_by_id(&djobs->jobs, j->id, 1);
		}
		else
			jnext = j->next;
		j = jnext;
	}
}
