/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 08:54:08 by hwolff            #+#    #+#             */
/*   Updated: 2019/03/27 12:02:02 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

/*
** 7 - ; or &(jobs)
** 6 - ||
** 5 - &&
** 4 - |
** 3 - >&
** 2 - < or <<
** 1 - > or >>
** 0 - CMD
*/

static int		cont_sub_exec(t_data *data, t_ast *ast, int ret)
{
	if (ast->token->type == PIPE)
		data->param.interactive ? launch_job(data, ast)
			: (ret = exec_pipes(data, ast));
	else if (ast->token->type == DOUBLEPIPE || ast->token->type == DOUBLEAND)
		data->param.interactive ? launch_job(data, ast)
			: (ret = and_or(data, ast));
	else if (ast->token->type == SEMICOLON
		|| (ast->token->type == AND && !data->param.interactive))
		ret = exec_semicolon(data, ast);
	else if (ast->token->type == ASSIGNEMENT)
		ret = exec_assignement(data, ast);
	else if (ast->token->type == OP_PAR)
		ret = subshell_case(data, ast, &ret);
	else if (ast->token->type == OP_BRA || ast->token->type == CL_BRA)
		ret = exec_command_group(data, ast);
	else if (ast->token->type == NEWLINE)
		ret = exec_newline(data, ast);
	else if (ast->token->type == BANG)
		ret = bang(data, ast);
	return (ret);
}

static int		sub_exec_cmd_line(t_data *data, t_ast *ast, int ret)
{
	t_data_jobs		*djobs;

	djobs = get_data_jobs();
	if (ast->token->type == GREATAND)
	{
		ret = main_agregator(data, ast, GREATAND);
		if (djobs->shell_pgid != getpgid(getpid()))
			exit(ret);
	}
	else if (ast->token->type == LESSAND)
	{
		ret = main_agregator(data, ast, LESSAND);
		if (djobs->shell_pgid != getpgid(getpid()))
			exit(ret);
	}
	else if (ast->token->type == DOUBLELESS)
	{
		ret = exec_heredoc(data, ast);
		if (djobs->shell_pgid != getpgid(getpid()))
			exit(ret);
	}
	else
		ret = cont_sub_exec(data, ast, ret);
	return (ret);
}

static int		cont_exec(t_data *data, t_ast *ast, int ret, char **table)
{
	t_data_jobs		*djobs;

	djobs = get_data_jobs();
	if (ast->token->type == GREAT || ast->token->type == DOUBLEGREAT)
	{
		ret = exec_redirect(data, ast, ast->token->type);
		if (djobs->shell_pgid != getpgid(getpid()))
			exit(0);
	}
	else if (ast->token->type == LESS)
	{
		ret = exec_back_redirect(data, ast);
		if (djobs->shell_pgid != getpgid(getpid()))
			exit(0);
	}
	else
		ret = sub_exec_cmd_line(data, ast, ret);
	if (ast->token->type == WORD)
	{
		set_val(&data->env, "_", table[ft_strtablen(table) - 1]);
		data->param.status = ret;
		ft_strtabdel(&table);
	}
	return (ret);
}

int				exec_cmd_line(t_data *data, t_ast *ast)
{
	int				ret;
	char			**tabl;
	size_t			tablen;
	t_data_jobs		*djobs;

	djobs = get_data_jobs();
	tabl = NULL;
	tablen = 0;
	if (!ast)
		return (OK);
	expansion(data, ast);
	if (data->param.cancel)
		return (ERROR);
	ret = OK;
	if (ast->token->type == WORD
		&& (tablen = tokenlist_to_tab(&tabl, ast->token)) && tabl)
		ret = word_case(djobs, ast, &tabl, tablen);
	ret = cont_exec(data, ast, ret, tabl);
	return (ret);
}
