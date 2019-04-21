/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 08:47:21 by hwolff            #+#    #+#             */
/*   Updated: 2019/03/29 19:20:56 by pespalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		exec_heredoc(t_data *data, t_ast *ast)
{
	char	*path;
	int		ret;
	int		fd_g;
	int		fd_d;
	int		stdin;

	path = try_m(ft_strjoinfs("/tmp/.42sh-thd-",
			try_m(ft_itoa((int)ast->right_arg->valid)), FT_ARG2));
	fd_d = open(path, O_RDONLY);
	unlink(path);
	ft_strdel(&path);
	if (fd_d >= 0)
	{
		fd_g = (ast->left_arg ? ft_atoi(ast->left_arg->val) : 0);
		stdin = dup(fd_g);
		dup2(fd_d, fd_g);
		ret = exec_redirect2(data, ast);
		dup2(stdin, fd_g);
		close(fd_d);
		close(stdin);
		return (ret);
	}
	else
		return (put_error(ERROR, "Here-document not found"));
}
