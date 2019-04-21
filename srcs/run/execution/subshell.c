/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subshell.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 17:54:54 by hben-yah          #+#    #+#             */
/*   Updated: 2019/03/30 02:00:11 by aroblin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void
	args_to_cmd_line(t_data *data, int ac, char **av)
{
	int		i;

	try_m((data->command = ft_strnew(0)));
	i = 0;
	while (i < ac)
	{
		try_m(data->command = ft_strjoin3fs(data->command, " "
			, av[i], FT_ARG1));
		if (i + 1 == ac)
			try_m(data->command = ft_strjoinfs(data->command, "\n", FT_ARG1));
		++i;
	}
}

int
	subshell(t_data *data, int ac, char **av)
{
	int			status;

	reset_command(data);
	status = 0;
	data->param.interactive = 0;
	data->param.options = 0;
	args_to_cmd_line(data, ac, av);
	if (!check_command(data) && !data->param.cancel)
	{
		build_ast(data);
		status = exec_cmd_line(data, data->ast);
		astlist_del(&data->ast);
	}
	return (status);
}

int
	exec_subcmd(t_data *data, t_ast *ast)
{
	pid_t		pid;
	int			status;
	char		**table;
	size_t		tablen;

	if ((status = 0) || !ast || !ast->token)
		return (OK);
	table = NULL;
	if (!(tablen = tokenlist_to_tab(&table, ast->token)))
		return (MAJOR_ERROR);
	if ((pid = fork()) == -1)
		status = MAJOR_ERROR;
	else if (pid == 0)
		status = subshell(data, tablen - 2, table + 1);
	else
	{
		pid = waitpid(pid, &status, 0);
		ft_tabdel((void ***)&table);
		return (WIFEXITED(status) ? WEXITSTATUS(status) : ERROR);
	}
	ft_tabdel((void ***)&table);
	if (!pid)
		shell_exit(status);
	return (OK);
}
