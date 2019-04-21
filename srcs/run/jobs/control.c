/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 14:38:16 by hben-yah          #+#    #+#             */
/*   Updated: 2019/03/27 20:01:39 by ndubouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void		setup_jobs(t_job **jobs, t_ast **ast)
{
	t_job			*tmp;
	t_job			*job;
	t_data_jobs		*djobs;
	t_job			*next;

	job = NULL;
	djobs = get_data_jobs();
	create_job_struct(jobs, ast, 1, 0);
	djobs->current_token = djobs->token_list;
	create_job_struct(&job, ast, 1, 1);
	if (!djobs->jobs)
		djobs->jobs = job;
	else
		job_addend(&djobs->jobs, job);
	tmp = *jobs;
	while (tmp)
	{
		next = tmp->next;
		if (is_job_ctrl_bt(tmp->ast))
			remove_one_job_by_id(&djobs->jobs, tmp->id, 0);
		tmp = next;
	}
}

static void		signals(void)
{
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGTSTP, SIG_IGN);
	signal(SIGTTIN, SIG_IGN);
	signal(SIGTTOU, SIG_IGN);
}

static void		exec_jobs(t_job *job, t_data *data)
{
	t_job			*tmp;
	t_job			*current_job;
	t_data_jobs		*djobs;
	t_job			*next;

	djobs = get_data_jobs();
	current_job = NULL;
	tmp = job;
	while (tmp)
	{
		next = tmp->next;
		if (!is_job_ctrl_bt(tmp->ast))
		{
			djobs->current_id = tmp->id;
			djobs->old_current_id = djobs->current_id - 1;
			current_job = get_job_by_id(&djobs->jobs, djobs->current_id);
		}
		exec_cmd_line(data, tmp->ast);
		update_status();
		if ((!djobs->jobs || !current_job) && !is_job_ctrl_bt(tmp->ast))
			break ;
		tmp = next;
	}
}

void			control_jobs(t_data *data)
{
	t_job			*job;
	t_data_jobs		*djobs;
	t_job			*current_job;

	job = NULL;
	current_job = NULL;
	if (!data->ast)
		return ;
	djobs = get_data_jobs();
	while (tcgetpgrp(0) != (djobs->shell_pgid = getpgrp()))
		kill(-djobs->shell_pgid, SIGCONT);
	djobs->shell_pgid = getpid();
	setpgid(djobs->shell_pgid, djobs->shell_pgid);
	tcsetpgrp(0, djobs->shell_pgid);
	signals();
	clean_finish_jobs();
	setup_jobs(&job, &data->ast);
	exec_jobs(job, data);
	free_jobs_param(&job);
	clean_finish_jobs();
	tokenlist_del(&djobs->token_list);
}
