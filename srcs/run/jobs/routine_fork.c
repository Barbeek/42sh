/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_fork.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndubouil <ndubouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 18:12:09 by ndubouil          #+#    #+#             */
/*   Updated: 2019/03/26 22:14:04 by ndubouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void	init_routine_fork(t_data **data, t_data_jobs **djobs
	, t_job **current_job)
{
	*data = get_data();
	*djobs = get_data_jobs();
	*current_job = get_job_by_id(&(*djobs)->jobs, (*djobs)->current_id);
}

int			routine_fork(t_pipeline *pipeline, t_list *tmp, int *fds, int *pip)
{
	t_data_jobs		*djobs;
	t_job			*current_job;
	pid_t			pid;
	t_data			*data;

	init_routine_fork(&data, &djobs, &current_job);
	expansion(data, ((t_ast *)(tmp->content)));
	if (check_builtins(((t_ast *)(tmp->content))) && !tmp->next)
	{
		exec_cmd_line(data, ((t_ast *)(tmp->content)));
		return (1);
	}
	find_path(data, ((t_ast *)tmp->content)->token->val);
	if ((pid = fork()) < 0)
		return (put_error(ERROR, "fork error"));
	if (pid == 0)
	{
		if (!launch_process(data, ((t_ast *)(tmp->content)), fds, pip))
			return (0);
	}
	upt_pgid_and_process(current_job, pid);
	if (current_job)
		current_job->last_pid = pid;
	pipeline->last_pid = pid;
	return (1);
}
