/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_substitution.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 22:13:17 by hben-yah          #+#    #+#             */
/*   Updated: 2019/03/30 00:24:48 by aroblin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static char	*get_substit_result(t_data *data, char *cmd)
{
	int		fd[2];
	pid_t	pid;
	int		status;
	char	*ret;

	if (!*cmd || (pipe(fd) == -1) || (pid = fork()) == -1)
		return (try_m(ft_strdup("=")));
	else if (pid == 0)
	{
		dup2(fd[1], 1);
		close(fd[1]);
		close(fd[0]);
		write(1, "=", 1);
		++data->param.subcmd;
		shell_exit(subshell(data, 1, &cmd));
	}
	close(fd[1]);
	waitpid(pid, &status, 0);
	ret = read_input(fd[0]);
	close(fd[0]);
	return (ret);
}

static void	trim_result(char **s)
{
	char **t;
	char *res;

	t = try_m(ft_split_chars(*s, ft_isspace_wnt));
	res = try_m(ft_strtabstrjoinf(t, ' '));
	*s = ft_strover(*s, res);
}

void		exp_substit_cmd(char **str, t_data *data)
{
	char	*res;
	char	*beg;
	char	*end;

	while (((beg = ft_strstr(*str, "$(")) && *(beg + 2) != '('
		&& *(end = walkparenthese(beg + 2)))
		|| (*(beg = walkbacktick(*str)) && *(beg + 1)
			&& *(end = walkbacktick(beg + 1))))
	{
		if (*beg == '$')
			ft_memset((void *)beg, 0, 2) && ++beg;
		else
			ft_memset((void *)beg, 0, 1);
		ft_memset((void *)end, 0, 1);
		beg = try_m(ft_strdup(++beg));
		exp_substit_cmd(&beg, data);
		res = get_substit_result(data, beg);
		trim_result(&res);
		*str = try_m(ft_strjoin3fs(*str, res + 1, end + 1, FT_ARG1));
		ft_strdel(&res);
		ft_strdel(&beg);
	}
}
