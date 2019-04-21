/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_jobs_status.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroblin <aroblin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 07:21:44 by aroblin           #+#    #+#             */
/*   Updated: 2019/03/26 22:14:44 by ndubouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void		stopped_case(int st, t_job **job, t_process **process)
{
	t_data_jobs *djobs;

	djobs = get_data_jobs();
	(*process)->stopped = 1;
	if (WSTOPSIG(st) == 18)
		if (job_is_stopped(*job))
		{
			(*job)->ground = 0;
			(*job)->stopped = 1;
			ft_putchar('\n');
			print_classic_jobs(*job, djobs);
		}
}

static void		print_ctrl_z_and_upt(t_process *process, t_job *job, int st
	, t_data_jobs *djobs)
{
	t_job	*current_job;
	t_data	*data;

	data = get_data();
	current_job = get_job_by_id(&djobs->jobs, djobs->current_id);
	if (WIFSTOPPED(st))
	{
		stopped_case(st, &job, &process);
		return ;
	}
	process->stopped = 0;
	process->completed = 1;
	if (current_job)
		current_job->pgid = 0;
	update_last_status(WEXITSTATUS(st));
	if (get_sig_str(WTERMSIG(st)) != NULL)
	{
		ft_putstrnbr("[", job->id, "]    ");
		ft_putstr4(get_sig_str(WTERMSIG(st)), "    ", job->command, "\n");
	}
}

int				mark_process_status(pid_t pid, int status, t_data_jobs *djobs)
{
	t_job		*job;
	t_process	*process;

	if (pid > 0)
	{
		job = djobs->jobs;
		while (job)
		{
			process = job->first_process;
			while (process)
			{
				if (process->pid == pid)
				{
					process->status = status;
					print_ctrl_z_and_upt(process, job, status, djobs);
					return (0);
				}
				process = process->next;
			}
			job = job->next;
		}
		return (-1);
	}
	return (-1);
}

void			wait_for_job(t_job *job)
{
	pid_t			pid;
	t_data_jobs		*djobs;
	int				status;

	djobs = get_data_jobs();
	pid = waitpid(WAIT_ANY, &status, WUNTRACED);
	while (!mark_process_status(pid, status, djobs)
		&& !job_is_stopped(job) && !job_is_completed(job))
		pid = waitpid(WAIT_ANY, &status, WUNTRACED);
}

void			update_status(void)
{
	pid_t			pid;
	t_data_jobs		*djobs;
	t_data			*data;
	int				status;

	data = get_data();
	djobs = get_data_jobs();
	pid = waitpid(WAIT_ANY, &status, WUNTRACED | WNOHANG);
	while (!mark_process_status(pid, status, djobs))
		pid = waitpid(WAIT_ANY, &status, WUNTRACED | WNOHANG);
}
