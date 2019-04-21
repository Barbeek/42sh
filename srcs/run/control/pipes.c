/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolff <hwolff@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 18:57:00 by hwolff            #+#    #+#             */
/*   Updated: 2019/03/09 13:36:10 by ndubouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void
	exec_next_cmd(t_data *data, t_ast *ast, int fildes[2])
{
	int		ret;

	dup2(fildes[0], 0);
	close(fildes[0]);
	close(fildes[1]);
	ret = exec_cmd_line(data, ast->right);
	shell_exit(ret);
}

static void
	exec_cmd(t_data *data, t_ast *ast, int fildes[2])
{
	int		ret;

	dup2(fildes[1], 1);
	close(fildes[0]);
	close(fildes[1]);
	ret = exec_cmd_line(data, ast->left);
	shell_exit(ret);
}

static int
	exec_one_pipe(t_data *data, t_ast *ast, int fildes[2])
{
	int		pid[2];
	int		stat[2];

	if ((pid[0] = fork()) == -1)
		return (put_error(ERROR, "fork error"));
	else if (!pid[0])
		exec_next_cmd(data, ast, fildes);
	if ((pid[1] = fork()) == -1)
		return (put_error(ERROR, "fork error"));
	else if (!pid[1])
		exec_cmd(data, ast, fildes);
	close(fildes[0]);
	close(fildes[1]);
	waitpid(pid[0], &stat[0], 0);
	waitpid(pid[1], &stat[1], 0);
	if ((WIFEXITED(stat[0])))
		return (WEXITSTATUS(stat[0]));
	return (WIFEXITED(stat[1]) ? WEXITSTATUS(stat[1]) : ERROR);
}

int
	exec_pipes(t_data *data, t_ast *ast)
{
	int		fildes[2];

	if (pipe(fildes) == -1)
		return (put_error(ERROR, "pipe error"));
	return (exec_one_pipe(data, ast, fildes));
}
