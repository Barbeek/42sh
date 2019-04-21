/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_jobs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroblin <aroblin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 14:45:20 by aroblin           #+#    #+#             */
/*   Updated: 2019/03/08 16:26:30 by aroblin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int			print_process_group(t_job *jobs)
{
	if (!jobs)
		return (EXIT_FAILURE);
	ft_putnbr(jobs->pgid);
	ft_putchar('\n');
	return (EXIT_SUCCESS);
}

void		print_id(t_job *jobs, t_data_jobs *djobs)
{
	ft_putstrnbr("[", jobs->id, "]");
	if (jobs->id == djobs->current_id)
		ft_putstr("+   ");
	else if (jobs->next && jobs->next->id == djobs->current_id)
		ft_putstr("-   ");
	else
		ft_putstr("    ");
}

int			print_classic_jobs(t_job *jobs, t_data_jobs *djobs)
{
	t_process	*tmp;

	if (!jobs)
		return (EXIT_FAILURE);
	tmp = jobs->first_process;
	if (!tmp)
		return (EXIT_FAILURE);
	print_id(jobs, djobs);
	if (job_is_stopped(jobs))
	{
		while (!get_classic_sig(WSTOPSIG(tmp->status)))
			tmp = tmp->next;
		ft_putstr2(get_classic_sig(WSTOPSIG(tmp->status)), "\t\t");
	}
	else
		ft_putstr("Running\t\t\t");
	ft_putendl(jobs->command);
	return (EXIT_SUCCESS);
}

int			print_detail_jobs(t_job *jobs, t_data_jobs *djobs)
{
	char		*sig;
	t_process	*tmp;

	sig = NULL;
	if (!jobs)
		return (EXIT_SUCCESS);
	tmp = jobs->first_process;
	if (!tmp)
		return (EXIT_FAILURE);
	print_id(jobs, djobs);
	ft_putnbr(jobs->pgid);
	ft_putchar(' ');
	if (job_is_stopped(jobs))
	{
		while (!get_detail_sig(WSTOPSIG(tmp->status)))
			tmp = tmp->next;
		sig = get_detail_sig(WSTOPSIG(tmp->status));
		ft_putstr2(sig, "\t\t");
		ft_strdel(&sig);
	}
	else
		ft_putstr("Running\t\t\t");
	ft_putendl(jobs->command);
	return (EXIT_SUCCESS);
}

int			print_job_list(t_job *jobs, t_data_jobs *djobs, char *opt)
{
	if (!jobs)
		return (EXIT_FAILURE);
	while (jobs)
	{
		if (is_l_opt(opt))
			print_detail_jobs(jobs, djobs);
		else if (is_p_opt(opt))
			print_process_group(jobs);
		else
			print_classic_jobs(jobs, djobs);
		jobs = jobs->next;
	}
	return (EXIT_SUCCESS);
}
