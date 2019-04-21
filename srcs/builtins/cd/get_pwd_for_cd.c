/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pwd_for_cd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndubouil <ndubouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 22:33:38 by ndubouil          #+#    #+#             */
/*   Updated: 2019/03/11 15:02:05 by ndubouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static int		home_cd(char **pwd, char **cdenv)
{
	char			*str;

	if (!cdenv[0])
	{
		ft_putendl(""SH_NAME": cd: HOME not set");
		return (0);
	}
	str = ft_strdup((cdenv)[0]);
	*pwd = get_final_path(&str, cdenv);
	ft_strdel(&str);
	return (1);
}

static int		oldpwd_cd(char **pwd, char **cdenv)
{
	char			*str;

	if (!cdenv[1])
	{
		ft_putendl(""SH_NAME": cd: OLDPWD not set");
		return (0);
	}
	str = ft_strdup((cdenv)[1]);
	*pwd = get_final_path(&str, cdenv);
	ft_strdel(&str);
	return (1);
}

char			*get_pwd_for_cd(int pos_args, char **args, char **cdenv)
{
	char		*pwd;
	char		*str;

	if (pos_args == 0 || !args[pos_args] || !args[pos_args][0])
	{
		if (!home_cd(&pwd, cdenv))
			return (0);
	}
	else if (ft_strcmp(args[pos_args], "-") == 0)
	{
		if (!oldpwd_cd(&pwd, cdenv))
			return (0);
	}
	else
	{
		str = ft_strdup(args[pos_args]);
		pwd = get_final_path(&str, cdenv);
		ft_strdel(&str);
	}
	return (pwd);
}
