/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 20:03:53 by hben-yah          #+#    #+#             */
/*   Updated: 2019/03/24 13:12:49 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		export_var(t_data *data, char *line)
{
	char	*key;
	char	*value;
	int		ret;

	if (!line || !*line)
		return (0);
	ret = 0;
	if ((value = ft_strchr(line, '=')))
	{
		key = try_m(ft_strsub(line, 0, ++value - 1 - line));
		ret = set_val(&data->env, key, value);
		ret = unset_val(&data->loc, key);
		ft_strdel(&key);
	}
	else if ((value = get_val(data->loc, line)))
	{
		ret = set_val(&data->env, line, value);
		ret = unset_val(&data->loc, line);
	}
	return (ret);
}
