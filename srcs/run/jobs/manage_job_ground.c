/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_job_ground.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroblin <aroblin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 07:14:01 by aroblin           #+#    #+#             */
/*   Updated: 2019/03/26 20:51:12 by ndubouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	put_job_in_foreground(t_job *job, int cont)
{
	t_data_jobs	*djobs;
	t_data		*data;

	djobs = get_data_jobs();
	data = get_data();
	if (!is_job_ctrl_bt(job->ast))
		djobs->current_id = job->id;
	tcsetpgrp(djobs->shell_terminal, job->pgid);
	if (cont)
		kill(-job->pgid, SIGCONT);
	job->ground = 1;
	wait_for_job(job);
	tcsetpgrp(djobs->shell_terminal, djobs->shell_pgid);
	tcgetattr(djobs->shell_terminal, &job->tmodes);
	tcsetattr(djobs->shell_terminal, TCSADRAIN, &data->term_dft_config);
}

void	put_job_in_background(t_job *job, int cont)
{
	t_data_jobs	*djobs;
	t_process	*process;
	t_data		*data;
	t_job		*current_job;

	djobs = get_data_jobs();
	data = get_data();
	current_job = get_job_by_id(&djobs->jobs, djobs->current_id);
	job->ground = 0;
	process = NULL;
	if (!is_job_ctrl_bt(job->ast))
		djobs->current_id = job->id;
	if (cont)
	{
		process = job->first_process;
		while (process)
		{
			process->stopped = 0;
			process = process->next;
		}
		kill(-job->pgid, SIGCONT);
	}
	if (current_job)
		data->param.last_bg_pid = current_job->pgid;
	set_val_nbr(&data->spe, "!", getpid());
}
