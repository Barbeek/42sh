/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_agregator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 08:48:02 by hwolff            #+#    #+#             */
/*   Updated: 2019/03/07 07:47:51 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

/*
** 2> : redirige les erreurs dans un fichier (s'il existe déjà, il sera écrasé);
** 2>&1 : redirige les erreurs au même endroit et de la même façon que la
** sortie standard
**          ne fonctionne que sur ksh;
** 2>&- : ferme la sortie indiquee
** >& : est egal a 2>&1, mais ne fonctionne que sur csh ou tcsh
** 1>&2
*/

static int
	display_redir_error(char *arg, int no_mess)
{
	const char	*mess[3] = {"Bad file descriptor",
							"Permission denied", "ambiguous redirect"};
	char		*c;

	if (no_mess > 0 && no_mess < 4)
	{
		if (arg && (c = ft_strrchr(arg, '-')) && *c && !*(c + 1))
			*c = 0;
		put_error2(ERROR, arg, (char *)mess[no_mess - 1]);
	}
	return (ERROR);
}

static int
	aggregation(t_data *data, t_ast *ast, int fd[2], int closed)
{
	int		ret;
	int		leftfd;
	int		rightfd;

	if (fd[0] != fd[1])
	{
		if (!check_fd(fd[1]))
			return (display_redir_error(ast->right_arg->val, 1));
		leftfd = dup(fd[0]);
		dup2(fd[1], fd[0]);
		rightfd = dup(fd[1]);
		closed && close(fd[1]);
	}
	if (ast->right)
		ret = exec_cmd_line(data, ast->right);
	if (ast->left)
		ret = exec_cmd_line(data, ast->left);
	if (fd[0] != fd[1])
	{
		dup2(rightfd, fd[1]);
		close(rightfd);
		dup2(leftfd, fd[0]);
		close(leftfd);
	}
	return (ret);
}

static int
	close_fd(t_data *data, t_ast *ast, int fd)
{
	int		ret;
	int		leftfd;

	leftfd = dup(fd);
	close(fd);
	if (ast->right)
		ret = exec_cmd_line(data, ast->right);
	if (ast->left)
		ret = exec_cmd_line(data, ast->left);
	dup2(leftfd, fd);
	close(leftfd);
	return (ret);
}

static int
	redirect_stdout_and_err_to_file(t_data *data, t_ast *ast)
{
	int		ret;
	int		file_fd;
	int		stdout;
	int		stderr;

	file_fd = open(ast->right_arg->val, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (file_fd >= 0)
	{
		stdout = dup(1);
		dup2(file_fd, 1);
		stderr = dup(2);
		dup2(1, 2);
		ast->right && (ret = exec_cmd_line(data, ast->right));
		ast->left && (ret = exec_cmd_line(data, ast->left));
		write(1, "\0", 0);
		dup2(stderr, 2);
		close(stderr);
		dup2(stdout, 1);
		close(stdout);
		close(file_fd);
		return (ret);
	}
	else
		return (display_redir_error(ast->right_arg->val
				? ast->right_arg->val : "", 2));
}

/*
** mode :
** 0 : no fd, no -    <== only with no left fd or = 1,
**                             redir 1 and 2, always ERROR with <&
** 1 : no fd, -       <== ERROR
** 2 : fd, no -       <== redir
** 3 : fd, -          <== redir and close
** 4 : empty, -       <== close left fd
*/

int
	main_agregator(t_data *data, t_ast *ast, int type)
{
	int		fd[2];
	int		mode;

	if (!ast->right_arg)
		return (display_redir_error(NULL, 3));
	fd[0] = ast->left_arg ? ft_atoi(ast->left_arg->val) : type == GREATAND;
	fd[1] = ft_atoi(ast->right_arg->val);
	mode = check_word(ast->right_arg->val);
	if (fd[0] == 1 && mode == 0 && type == GREATAND)
		return (redirect_stdout_and_err_to_file(data, ast));
	else if (mode == 2)
		return (aggregation(data, ast, fd, 0));
	else if (mode == 3)
		return (aggregation(data, ast, fd, 1));
	else if (mode == 4)
		return (close_fd(data, ast, fd[0]));
	return (display_redir_error(ast->right_arg->val, 3));
}
