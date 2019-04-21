/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd_line_tools.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndubouil <ndubouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 16:20:32 by ndubouil          #+#    #+#             */
/*   Updated: 2019/03/26 22:15:08 by ndubouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		subshell_case(t_data *data, t_ast *ast, int *ret)
{
	char		**table;
	int			tablen;
	t_data_jobs	*djobs;
	int			status;

	if (data->param.interactive)
		launch_job(data, ast);
	else
	{
		djobs = get_data_jobs();
		if (djobs->shell_pgid != getpid() && isatty(0))
		{
			if (!(tablen = tokenlist_to_tab(&table, ast->token)))
				return (MAJOR_ERROR);
			status = subshell(data, tablen - 2, table + 1);
			ft_tabdel((void ***)&table);
			exit(status);
		}
		else
		{
			*ret = exec_subcmd(data, ast);
			update_last_status(*ret);
		}
	}
	return (*ret);
}

int		word_case(t_data_jobs *djobs, t_ast *ast, char ***tabl, int len)
{
	int		ret;
	t_data	*data;

	data = get_data();
	ret = 0;
	if ((ret = exec_if_builtin(data, len, *tabl)) != -1)
	{
		update_last_status(ret);
		return (ret);
	}
	if (data->param.interactive)
	{
		if (getpid() == djobs->shell_pgid)
			launch_job(data, ast);
		else
			ex_exec_job_control(data, data->env, *tabl);
	}
	else
	{
		ret = ex_exec(data, data->env, *tabl);
		update_last_status(ret);
	}
	return (ret);
}
