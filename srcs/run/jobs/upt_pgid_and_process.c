/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   upt_pgid_and_process.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndubouil <ndubouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 18:16:29 by ndubouil          #+#    #+#             */
/*   Updated: 2019/03/26 20:30:29 by ndubouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void		upt_pgid_and_process(t_job *current_job, pid_t pid)
{
	t_process	*process;

	try_m(process = ft_memalloc(sizeof(t_process)));
	if (!current_job)
		return ;
	if (current_job->pgid == 0)
		current_job->pgid = pid;
	setpgid(pid, current_job->pgid);
	if (kill(current_job->pgid, 0) == -1)
	{
		current_job->pgid = pid;
		setpgid(pid, pid);
	}
	process->pid = pid;
	if (!current_job->first_process)
		current_job->first_process = process;
	else
		process_addend(&current_job->first_process, process);
}
