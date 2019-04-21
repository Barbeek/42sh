/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_special_param.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 11:37:55 by hben-yah          #+#    #+#             */
/*   Updated: 2019/03/23 11:53:36 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		set_special(t_data *data, char *key, char *value)
{
	if (!key || !*key || !value)
		return (0);
	return (set_val(&data->spe, key, value));
}

int		set_special_line(t_data *data, char *line)
{
	char	*key;
	char	*value;
	int		ret;

	if (!line || !*line)
		return (0);
	if ((value = ft_strchr(line, '=')))
	{
		key = try_m(ft_strsub(line, 0, value++ - line));
		ret = set_special(data, key, value);
		ft_strdel(&key);
		return (ret);
	}
	return (0);
}

int		set_special_nbr(t_data *data, char *key, long value)
{
	char	*v;
	int		ret;

	if (!key || !*key)
		return (0);
	v = try_m(ft_ltoa(value));
	ret = set_special(data, key, v);
	ft_strdel(&v);
	return (ret);
}

int		set_special_nbr_key(t_data *data, long key, char *value)
{
	char	*k;
	int		ret;

	if (!value)
		return (0);
	k = try_m(ft_ltoa(key));
	ret = set_special(data, k, value);
	ft_strdel(&k);
	return (ret);
}
