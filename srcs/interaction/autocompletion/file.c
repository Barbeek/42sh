/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 20:50:44 by hben-yah          #+#    #+#             */
/*   Updated: 2019/03/29 20:17:32 by aroblin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

char
	*remove_backslash_before_spechar(char *s)
{
	int		i;
	int		decal;
	int		len;

	i = 0;
	decal = 0;
	len = ft_strlen(s);
	while (i < len - decal)
	{
		if (s[i + decal] == '\\'
			&& ft_indexof(s[i + decal + 1], "|&;<>\"\'`\\()$ ") > -1)
			++decal;
		s[i] = s[i + decal];
		++i;
	}
	while (i < len)
		s[i++] = 0;
	return (s);
}

char
	*insert_backslash_before_spechar(char *s)
{
	int		i;
	int		decal;
	char	*ret;
	char	*tmp;

	try_m((ret = ft_strdup(s)));
	i = 0;
	decal = 0;
	while (s[i])
	{
		if (ft_indexof(s[i], "|&;<> ") > -1)
		{
			try_m((tmp = ft_strnew(ft_strlen(ret) + 1)));
			ft_strncpy(tmp, ret, i + decal);
			tmp[i + decal] = '\\';
			ft_strcpy(tmp + i + decal + 1, ret + i + decal);
			ft_strdel(&ret);
			ret = tmp;
			++decal;
		}
		++i;
	}
	return (ret);
}

static int
	is_a_directory(char *dir, char *file)
{
	struct stat		stats;
	char			*path;
	int				ret;

	try_m((path = ft_strjoin(dir, file)));
	ret = 0;
	if (stat(path, &stats) != -1)
		ret = S_ISDIR(stats.st_mode);
	ft_strdel(&path);
	return (ret);
}

void
	check_file(t_edl *edl, char *path, char *file, char *entry)
{
	int		len;

	entry = try_m(insert_backslash_before_spechar(entry));
	file = try_m(ft_strdup(file));
	len = ft_strlen(file);
	if (ft_strnequ(entry, file, len))
	{
		if (is_a_directory(path, entry))
		{
			entry = try_m(ft_strjoinfs(entry, "/", FT_ARG1));
			file = try_m(ft_strover(file, ft_strdup(entry)));
		}
		else
			file = try_m(ft_strover(file, ft_strjoin(entry, " ")));
		set_compl_suffix(edl->sugg.list, file + len);
		ft_strdel(&file);
		ft_strtabadd(&edl->sugg.list, entry) && try_m(edl->sugg.list);
		len = ft_strlen(entry);
		++edl->sugg.len;
		edl->sugg.max = (edl->sugg.max < len ? len : edl->sugg.max);
	}
	else
		ft_strdel2(&file, &entry);
}

void
	complete_file(t_edl *edl, t_token *tok)
{
	DIR				*dir;
	struct dirent	*ent;
	char			*n;
	char			*path;

	if ((n = ft_strrchr(tok->val, '/')))
		try_m(path = ft_strsub(tok->val, 0, n++ - tok->val + 1));
	else
	{
		try_m(path = ft_strdup("./"));
		n = tok->val;
	}
	if ((dir = opendir(path)) && readdir(dir) && readdir(dir))
	{
		while (edl->sugg.len < 102 && (ent = readdir(dir)))
			check_file(edl, path, n, ent->d_name);
		closedir(dir);
	}
	ft_strdel(&path);
}
