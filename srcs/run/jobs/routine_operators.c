/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_operators.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndubouil <ndubouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 20:14:52 by ndubouil          #+#    #+#             */
/*   Updated: 2019/03/26 20:54:40 by ndubouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void	foreground_case(t_list *lst, t_job *current_job, t_data_jobs *djobs)
{
	t_pipeline	*pipeline;

	while (lst)
	{
		update_status();
		pipeline = (*((t_pipeline **)(lst->content)));
		if (pipeline->prev_operator == DOUBLEAND)
		{
			if (!djobs->last_status)
				routine_pipe(pipeline);
		}
		else if (pipeline->prev_operator == DOUBLEPIPE)
		{
			if (djobs->last_status)
				routine_pipe(pipeline);
		}
		else
		{
			routine_pipe(pipeline);
		}
		if (current_job)
			if (current_job->ground == 1)
				put_job_in_foreground(current_job, 0);
		lst = lst->next;
	}
}

static void	routine_background(t_list *lst, int *status)
{
	t_pipeline	*pipeline;

	while (lst)
	{
		pipeline = (*((t_pipeline **)(lst->content)));
		if (pipeline->prev_operator == DOUBLEAND)
		{
			if (!(*status))
				routine_pipe(pipeline);
		}
		else if (pipeline->prev_operator == DOUBLEPIPE)
		{
			if ((*status))
				routine_pipe(pipeline);
		}
		else
			routine_pipe((*((t_pipeline **)(lst->content))));
		waitpid(pipeline->last_pid, status, WUNTRACED);
		while (WIFSTOPPED((*status)))
		{
			kill(-getpid(), SIGSTOP);
			waitpid(pipeline->last_pid, status, WUNTRACED);
		}
		lst = lst->next;
	}
}

static void	background_case(t_list *lst, t_job *current_job)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid == 0)
	{
		if (current_job)
		{
			if (current_job->pgid == 0)
				current_job->pgid = getpid();
			setpgid(getpid(), current_job->pgid);
		}
		routine_background(lst, &status);
		exit(status);
	}
	if (current_job)
	{
		if (current_job->pgid == 0)
			current_job->pgid = pid;
		setpgid(pid, current_job->pgid);
	}
	upt_pgid_and_process(current_job, pid);
	update_status();
}

void		routine_operators(t_list *lst)
{
	t_list		*tmp;
	t_data_jobs	*djobs;
	t_job		*current_job;

	djobs = get_data_jobs();
	current_job = get_job_by_id(&djobs->jobs, djobs->current_id);
	tmp = lst;
	if (!tmp->next)
	{
		routine_pipe((*((t_pipeline **)(tmp->content))));
	}
	else
	{
		if (current_job && current_job->ground == 0)
			background_case(tmp, current_job);
		else
			foreground_case(tmp, current_job, djobs);
	}
}
