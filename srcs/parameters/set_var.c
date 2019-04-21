/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_var.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 20:03:40 by hben-yah          #+#    #+#             */
/*   Updated: 2019/03/27 13:00:11 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		set_var(t_data *data, char *key, char *value)
{
	char	**v;

	if (!key || !*key || !value)
		return (0);
	if (ft_strequ(key, "PATH"))
		empty_hash(data->hashtable);
	if ((v = get_keyval(data->env, key)))
		*v = ft_strover(*v, try_m(ft_strjoin3(key, "=", value)));
	else
		return (set_val(&data->loc, key, value));
	return (1);
}

int		set_var_line(t_data *data, char *line)
{
	char	*key;
	char	*value;
	int		ret;

	if (!line || !*line)
		return (0);
	if ((value = ft_strchr(line, '=')))
	{
		key = try_m(ft_strsub(line, 0, value++ - line));
		ret = set_var(data, key, value);
		ft_strdel(&key);
		return (ret);
	}
	return (0);
}

int		set_var_nbr(t_data *data, char *key, long value)
{
	char	*v;
	int		ret;

	if (!key || !*key)
		return (0);
	v = try_m(ft_ltoa(value));
	ret = set_var(data, key, v);
	ft_strdel(&v);
	return (ret);
}

int		set_var_nbr_key(t_data *data, long key, char *value)
{
	char	*k;
	int		ret;

	if (!value)
		return (0);
	k = try_m(ft_ltoa(key));
	ret = set_var(data, k, value);
	ft_strdel(&k);
	return (ret);
}
