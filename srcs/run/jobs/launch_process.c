/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndubouil <ndubouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 19:35:07 by ndubouil          #+#    #+#             */
/*   Updated: 2019/03/26 20:32:39 by ndubouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void	signals(void)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	signal(SIGTSTP, SIG_DFL);
	signal(SIGTTIN, SIG_DFL);
	signal(SIGTTOU, SIG_DFL);
	signal(SIGCHLD, SIG_DFL);
}

static int	dup_process(int infile, int outfile, int *pip)
{
	if (infile != 0)
	{
		if (dup2(infile, 0) == -1)
			return (0);
		close(infile);
	}
	if (outfile != 1)
	{
		if (dup2(outfile, 1) == -1)
			return (0);
		close(outfile);
	}
	close(pip[0]);
	close(pip[1]);
	return (1);
}

static void	update_current_job_pgid(t_job **current_job)
{
	if (!(*current_job))
		return ;
	if ((*current_job)->pgid == 0)
		(*current_job)->pgid = getpid();
	setpgid(getpid(), (*current_job)->pgid);
}

static void	process_execution(t_ast *ast, t_data *data, char ***table)
{
	int		ret;
	int		tablen;

	if (ast->token->type == WORD)
	{
		tablen = tokenlist_to_tab(table, ast->token);
		if ((ret = exec_if_builtin(data, tablen, *table)) == -1)
			ret = ex_exec_job_control(data, data->env, *table);
		ft_tabdel((void ***)table);
		exit(ret);
	}
	else if (ast->token->type == OP_PAR)
	{
		tablen = tokenlist_to_tab(table, ast->token);
		data->param.interactive = 0;
		ret = subshell(data, tablen, *table);
		ft_tabdel((void ***)table);
		exit(ret);
	}
	else
		exec_cmd_line(data, ast);
}

int			launch_process(t_data *data, t_ast *ast, int *fds, int *pip)
{
	t_data_jobs		*djobs;
	t_job			*current_job;
	char			**table;

	if (dup_process(fds[0], fds[1], pip) == 0)
		return (0);
	djobs = get_data_jobs();
	current_job = get_job_by_id(&djobs->jobs, djobs->current_id);
	update_current_job_pgid(&current_job);
	if (current_job)
		if (current_job->ground == 1)
			tcsetpgrp(djobs->shell_terminal, current_job->pgid);
	signals();
	process_execution(ast, data, &table);
	return (1);
}
