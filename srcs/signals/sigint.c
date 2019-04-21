/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sigint.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 18:54:09 by hben-yah          #+#    #+#             */
/*   Updated: 2019/03/29 20:58:24 by ndubouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	handle_sigint(void)
{
	t_data_jobs		*djobs;
	t_job			*jobs;

	djobs = get_data_jobs();
	jobs = get_job_by_id(&djobs->jobs, djobs->current_id);
	if (jobs && jobs->pgid && jobs->ground == 1)
		kill(-jobs->pgid, SIGTERM);
}

void	edl_sigint_handler(int sig)
{
	t_data	*data;

	if (sig == SIGINT)
	{
		data = get_data();
		data->param.status = ERROR;
		reset_command(data);
		ft_putchar_fd('\n', FD_EDL);
		set_prompt(&data->edl);
		display_prompt(&data->edl);
		init_edl(&data->edl);
	}
}

void	here_edl_sigint_handler(int sig)
{
	t_data	*data;

	if (sig == SIGINT)
	{
		data = get_data();
		data->param.status = ERROR;
		ft_strdel(&data->command);
		data->edl.hist.cur = 0;
		reset_edition_current_line(&data->edl);
		data->edl.tabul = 0;
		data->edl.eof = 0;
		data->edl.incomp_type = INC_EMPTY;
		ft_putchar_fd('\n', FD_EDL);
		set_prompt(&data->edl);
		display_prompt(&data->edl);
		init_edl(&data->edl);
		data->param.cancel = 1;
	}
}
