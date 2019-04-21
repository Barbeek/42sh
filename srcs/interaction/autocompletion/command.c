/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 20:51:04 by hben-yah          #+#    #+#             */
/*   Updated: 2019/03/17 18:39:49 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void
	complete_from_each_env_path(t_edl *edl, char *path, t_token *tok)
{
	DIR				*dir;
	struct dirent	*ent;
	int				i;

	i = 0;
	remove_backslash_before_spechar(path);
	if ((dir = opendir(path)) && readdir(dir) && readdir(dir))
	{
		while (edl->sugg.len < 102 && (ent = readdir(dir)))
			check_file(edl, path, tok->val, ent->d_name);
		closedir(dir);
		++i;
	}
}

static void
	complete_from_env_path(t_edl *edl, char **env, t_token *tok)
{
	char	**path;
	char	*param;
	int		i;

	if (edl->sugg.len < 102 && (param = get_val(env, "PATH")))
	{
		try_m(path = ft_strsplit(param, ':'));
		i = 0;
		remove_backslash_before_spechar(tok->val);
		while (path[i] && edl->sugg.len < 102)
			complete_from_each_env_path(edl, path[i++], tok);
		ft_strtabdel(&path);
	}
}

void
	complete_command(t_data *data, t_edl *edl, t_token *tok)
{
	if (!ft_strchr(tok->val, '/'))
	{
		complete_from_builtin(edl, tok);
		complete_from_alias(edl, data->alias, tok);
		complete_from_env_path(edl, data->env, tok);
	}
	else
		complete_file(edl, tok);
}
