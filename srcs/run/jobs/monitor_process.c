/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_process.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroblin <aroblin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 07:40:01 by aroblin           #+#    #+#             */
/*   Updated: 2019/03/08 16:13:29 by ndubouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		job_is_stopped(t_job *job)
{
	t_process	*process;

	process = job->first_process;
	while (process)
	{
		if (!process->completed && !process->stopped)
			return (0);
		process = process->next;
	}
	return (1);
}

int		job_is_completed(t_job *job)
{
	t_process	*process;

	process = job->first_process;
	while (process)
	{
		if (!process->completed)
			return (0);
		process = process->next;
	}
	return (1);
}
