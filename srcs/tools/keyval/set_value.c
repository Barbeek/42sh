/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_value.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 11:21:57 by hben-yah          #+#    #+#             */
/*   Updated: 2019/03/24 13:12:11 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		set_val(char ***vars, char *key, char *value)
{
	char	**v;
	char	*new;

	if (!vars || !key || !*key || !value)
		return (0);
	new = try_m(ft_strjoin3(key, "=", value));
	if ((v = get_keyval(*vars, key)))
		*v = ft_strover(*v, new);
	else if (!ft_strtabadd(vars, new))
	{
		free(new);
		try_m(vars);
	}
	else
		ft_sortstrtab(*vars);
	return (1);
}

int		set_keyval(char ***vars, char *line)
{
	char	*key;
	char	*value;
	int		ret;

	if (!vars || !line || !*line)
		return (0);
	if ((value = ft_strchr(line, '=')))
	{
		key = try_m(ft_strsub(line, 0, value++ - line));
		ret = set_val(vars, key, value);
		ft_strdel(&key);
		return (ret);
	}
	return (0);
}

int		set_val_nbr(char ***vars, char *key, long value)
{
	char	*v;
	int		ret;

	if (!key || !*key)
		return (0);
	v = try_m(ft_ltoa(value));
	ret = set_val(vars, key, v);
	ft_strdel(&v);
	return (ret);
}

int		set_key_nbr(char ***vars, long key, char *value)
{
	char	*k;
	int		ret;

	if (!value || !*value)
		return (0);
	k = try_m(ft_ltoa(key));
	ret = set_val(vars, k, value);
	ft_strdel(&k);
	return (ret);
}
