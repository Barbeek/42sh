/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 08:51:07 by hwolff            #+#    #+#             */
/*   Updated: 2019/03/27 13:07:34 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

char		**get_path(char **env, char **arg)
{
	char	**path;
	int		i;
	char	*tmp;

	i = 0;
	if ((!(path = NULL) && arg[0][0] != '/')
			&& !(ft_strnequ(arg[0], "./", 2))
			&& !(ft_strnequ(arg[0], "../", 3)))
	{
		while (env[i] && (ft_strncmp(env[i], "PATH=", 5) != 0))
			i++;
		if (!env[i] || !try_m(path = ft_strsplit(env[i], ':')))
			return (NULL);
		path[0] = ft_strncpy(path[0], path[0] + 5, ft_strlen(path[0]));
		i = -1;
		while (path[++i])
		{
			tmp = path[i];
			try_m((path[i] = ft_strjoin3(path[i], "/", arg[0])));
			ft_strdel(&tmp);
		}
	}
	return (path ? path : try_m(ft_strtabdup(&arg[0])));
}

static void	ex_exec_core(char **env, char **table, char **paths, t_data *data)
{
	int			i;
	t_data_jobs	*djobs;
	t_job		*current_job;
	char		*path;

	i = -1;
	djobs = get_data_jobs();
	current_job = get_job_by_id(&djobs->jobs, djobs->current_id);
	if (current_job)
		setpgid(getpid(), current_job->pgid);
	path = ht_get(data->hashtable, table[0]);
	if (path)
		execve(path, table, env);
	while (paths[++i])
	{
		if (access(paths[i], X_OK) == 0)
		{
			execve(paths[i], table, env);
			break ;
		}
	}
	put_error2(NOT_FOUND, *table, "command not found");
	ft_strtabdel(&table);
	ft_strtabdel(&paths);
	shell_exit(NOT_FOUND);
}

int			ex_exec_job_control(t_data *data, char **env, char **table)
{
	char			**paths;
	t_data_jobs		*djobs;

	djobs = get_data_jobs();
	if (!(paths = get_path(env, table)))
	{
		put_error2(NOT_FOUND, *table, "command not found");
		return (NOT_FOUND);
	}
	ex_exec_core(env, table, paths, data);
	ft_strtabdel(&paths);
	return (1);
}

int			ex_exec(t_data *data, char **env, char **table)
{
	int		status;
	char	**paths;
	int		childpid;

	(void)data;
	if (!(paths = get_path(env, table)))
	{
		put_error2(NOT_FOUND, *table, "command not found");
		return (NOT_FOUND);
	}
	if ((childpid = fork()) == -1)
		return (MAJOR_ERROR);
	if (childpid == 0)
		ex_exec_core(env, table, paths, data);
	waitpid(childpid, &status, 0);
	ft_strtabdel(&paths);
	if (WIFSIGNALED(status))
	{
		ft_putchar('\n');
		return (128 + status);
	}
	return (WIFEXITED(status) ? WEXITSTATUS(status) : ERROR);
}
