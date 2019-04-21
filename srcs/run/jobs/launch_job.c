/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_job.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndubouil <ndubouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 17:33:09 by ndubouil          #+#    #+#             */
/*   Updated: 2019/03/26 22:11:38 by ndubouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void	init_launch_job(t_list **lst, t_list **oplst, t_data_jobs **djobs
	, t_job **current_job)
{
	*lst = NULL;
	*oplst = NULL;
	*djobs = get_data_jobs();
	*current_job = get_job_by_id(&(*djobs)->jobs, (*djobs)->current_id);
}

int			launch_job(t_data *data, t_ast *ast)
{
	t_list			*lst;
	t_list			*oplst;
	t_data_jobs		*djobs;
	t_job			*current_job;

	(void)data;
	init_launch_job(&lst, &oplst, &djobs, &current_job);
	catch_signals();
	create_operators_lst(&oplst, ast, 0);
	routine_operators(oplst);
	if (current_job)
	{
		if (current_job->ground == 1)
			put_job_in_foreground(current_job, 0);
		else
		{
			put_job_in_background(current_job, 0);
			ft_putstrnbr("[", current_job->id, "] ");
			print_process_group(current_job);
		}
	}
	lstdel(&oplst, deloplst);
	return (1);
}
