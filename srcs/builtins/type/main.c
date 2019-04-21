/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolff <hwolff@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 15:48:34 by hwolff            #+#    #+#             */
/*   Updated: 2019/03/30 03:41:45 by aroblin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static char	**get_path_type(char **env, char *arg)
{
	char	**path;
	int		i;

	i = 0;
	if ((!(path = NULL) && (arg[0] != '/' || (arg[0] != '.' && arg[1] != '/'))))
	{
		while (env[i] && (ft_strncmp(env[i], "PATH=", 5) != 0))
			i++;
		if (!env[i] || !try_m(path = ft_strsplit(env[i], ':')))
			return (NULL);
		path[0] = ft_strmove(path[0], path[0] + 5);
		i = -1;
		while (path[++i])
			path[i] = try_m(ft_strjoin3fs(path[i], "/", arg, FT_ARG1));
	}
	return (path);
}

static int	access_path_ok(char *arg)
{
	ft_putstr3_fd(arg, " is /bin/", arg, 0);
	ft_putstr_fd("\n", 0);
	return (0);
}

static int	type_binary(char **path, char **av, int i)
{
	int		j;
	int		err;

	j = 0;
	err = 1;
	while (path[j])
	{
		if (access(path[j], X_OK) == 0)
		{
			err = access_path_ok(av[i]);
			break ;
		}
		j++;
	}
	j = 0;
	if (err != 0)
		error_type(av[i]);
	return (0);
}

int			sh_type(t_data *data, int ac, char **av)
{
	int		i;
	char	**path;

	i = 1;
	while (av[i] && data && ac)
	{
		path = NULL;
		if (av[1][0] == '-')
		{
			check_error_flags_type(av[1]);
			return (0);
		}
		else if (is_builtin(av[i]))
			ft_putstr2_fd(av[i], " is a shell builtin\n", 0);
		else if (is_type_alias(av[i], data))
			;
		else if (av[i][0] && (path = get_path_type(data->env, av[i])))
		{
			type_binary(path, av, i);
			ft_strtabdel(&path);
		}
		i++;
	}
	return (0);
}
