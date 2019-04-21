/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 16:57:23 by hben-yah          #+#    #+#             */
/*   Updated: 2019/03/29 20:16:23 by aroblin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

/*
** Command line lifecycle
** - display prompt
** 1 - read the command line
** 2 - lexical analysis (lex)
** 3 - parsing (check syntax error, inhibitors, etc)
** 4 - building the ast (abstract syntaxic tree)
** 5 - execute the commands with priorities
** 6 - reset
*/

void	run_non_interactive_shell(t_data *data)
{
	data->param.interactive = 0;
	data->param.options = 0;
	data->command = try_m(ft_strjoin(data->edl.line, "\n"));
	if (!check_command(data) && !data->param.cancel)
	{
		build_ast(data);
		exec_cmd_line(data, data->ast);
	}
}

void	run_interactive_shell(t_data *data)
{
	static void	(*steps[4])(t_data*) = {
		&compose_command,
		&build_ast,
		&control_jobs,
		&reset_command
	};
	int			i;

	i = 0;
	while (data->param.run && isatty(FD_IN))
	{
		steps[i](data);
		if (data->param.cancel)
		{
			reset_command(data);
			i = 0;
		}
		else
			i = (i + 1) % 4;
	}
}

/*
** Entrée principale du Shell
*/

int		main(int ac, char **av, char **env)
{
	t_data	*data;

	if (ac && av && env)
	{
		data = get_data();
		if (!init_shell(data, ac, av, env))
		{
			if (data->param.interactive)
				run_interactive_shell(data);
			else
				run_non_interactive_shell(data);
		}
		return (reset_shell(data));
	}
	return (OK);
}
