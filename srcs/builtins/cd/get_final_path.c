/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_final_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndubouil <ndubouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 19:33:08 by ndubouil          #+#    #+#             */
/*   Updated: 2019/03/20 16:09:23 by aroblin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static char		*get_complete_path(char *parent, char *name)
{
	char	*tmp;
	char	*result;

	if (parent == NULL || name == NULL)
		return (NULL);
	if (name[0] == '/')
		return (name);
	if (name[0] == '.' && name[1] == '/')
	{
		if (!(tmp = ft_strdup(&name[2])))
			return (NULL);
		ft_strdel(&name);
		name = tmp;
	}
	if (parent[ft_strlen(parent) - 1] == '/')
		tmp = ft_strdup(parent);
	else
		tmp = ft_strjoin(parent, "/");
	if (!tmp)
		return (NULL);
	if (!(result = ft_strjoin(tmp, name)))
		return (NULL);
	ft_strdel(&tmp);
	return (result);
}

static void		clean_absolute_path(char **path)
{
	char	**pwd_tab;
	char	*str;

	if ((*path)[0] == '/' && (*path)[1] != '.')
	{
		if (!(pwd_tab = ft_strsplit(*path, '/')))
			return ;
		if (!(str = ft_strjointab(pwd_tab, '/')))
		{
			ft_strtab_del(&pwd_tab);
			return ;
		}
		ft_strtab_del(&pwd_tab);
		ft_strdel(path);
		*path = ft_strdup(str);
		ft_strdel(&str);
	}
}

static void		del_tab(char ***arg_tab, char ***pwd_tab)
{
	ft_strtab_del(arg_tab);
	ft_strtab_del(pwd_tab);
}

static void		no_pwd(char **cdenv)
{
	char			pwd[4096];

	getcwd(pwd, 4096);
	cdenv[2] = ft_strdup(pwd);
}

char			*get_final_path(char **path, char **cdenv)
{
	char			**arg_tab;
	char			**pwd_tab;
	char			*str;

	if (!cdenv[2])
		no_pwd(cdenv);
	clean_absolute_path(path);
	if ((*path)[0] == '/' && (*path)[1] != '.')
		return (ft_strdup(get_complete_path(cdenv[2], *path)));
	if (!(arg_tab = ft_strsplit(*path, '/')))
		return (NULL);
	if (!(pwd_tab = ft_strsplit(cdenv[2], '/')))
		return (NULL);
	if (!build_pwd_tab(&arg_tab, &pwd_tab, ft_stringtab_len(pwd_tab)))
	{
		del_tab(&arg_tab, &pwd_tab);
		return (NULL);
	}
	if (!(str = ft_strjointab(pwd_tab, '/')))
		return (NULL);
	del_tab(&arg_tab, &pwd_tab);
	return (str);
}
