/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 14:09:13 by hben-yah          #+#    #+#             */
/*   Updated: 2019/03/11 15:03:38 by ndubouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

/*
**   http://pubs.opengroup.org/onlinepubs/9699919799/utilities/cd.html
*/

static int		manage_pwd(char **cdenv, char *pwd, int options)
{
	char		**nenv;
	char		**arg;
	t_data		*data;
	char		**tmp;

	data = get_data();
	try_m((nenv = ft_strtabdup(data->env)));
	try_m((arg = (char **)ft_memalloc(sizeof(char *) * 4)));
	if (cdenv[2])
		try_m(arg[2] = ft_strjoin("OLDPWD=", cdenv[2]));
	if (options & (1 << 28))
	{
		try_m(arg[1] = ft_strjoin("PWD=", getcwd(NULL, 0)));
		set_keyval(&nenv, arg[1]);
	}
	else
	{
		try_m(arg[1] = ft_strjoin("PWD=", pwd));
		set_keyval(&nenv, arg[1]);
	}
	set_keyval(&nenv, arg[2]);
	tmp = data->env;
	try_m((data->env = ft_strtabdup(nenv)));
	free_cd_tabs(tmp, nenv, arg);
	return (1);
}

int				change_directory(char *pwd, char **cdenv, int options)
{
	if (!check_path_errors(pwd))
		return (0);
	if ((chdir(pwd)) < 0)
	{
		ft_putstr3(""SH_NAME": cd: ", pwd, ": Permission denied\n");
		return (0);
	}
	return (manage_pwd(cdenv, pwd, options));
}

static void		init_cdenv(char **cdenv, char **env)
{
	int		i;

	i = 0;
	cdenv[0] = NULL;
	cdenv[1] = NULL;
	cdenv[2] = NULL;
	while (env[i])
	{
		if (ft_strncmp(env[i], "HOME=", 5) == 0)
			cdenv[0] = env[i] + 5;
		else if (ft_strncmp(env[i], "OLDPWD=", 7) == 0)
			cdenv[1] = env[i] + 7;
		else if (ft_strncmp(env[i], "PWD=", 4) == 0)
			cdenv[2] = env[i] + 4;
		i++;
	}
}

void			free_cd_tabs(char **tmp, char **nenv, char **narg)
{
	ft_strtabdel(&tmp);
	ft_strtabdel(&nenv);
	if (narg[0])
		ft_strdel(&narg[0]);
	if (narg[1])
		ft_strdel(&narg[1]);
	if (narg[2])
		ft_strdel(&narg[2]);
	free(narg);
}

int				sh_cd(t_data *data, int ac, char **av)
{
	char			*pwd;
	char			*cdenv[3];
	int				pos_args;
	int				options;

	(void)ac;
	options = 0;
	pos_args = 0;
	if (!*data->env)
		return (OK);
	cd_options_parser(av, &options, &pos_args);
	init_cdenv(&cdenv[0], data->env);
	if (!(pwd = get_pwd_for_cd(pos_args, av, &cdenv[0])))
		return (EXIT_FAILURE);
	if (!change_directory(pwd, &cdenv[0], options))
	{
		ft_strdel(&pwd);
		return (EXIT_FAILURE);
	}
	ft_strdel(&pwd);
	return (EXIT_SUCCESS);
}
