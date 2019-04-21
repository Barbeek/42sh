/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_param.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 11:35:47 by hben-yah          #+#    #+#             */
/*   Updated: 2019/03/29 19:47:04 by ndubouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

char	*get_param(t_data *data, char *key)
{
	char	**v;

	if (!key || !*key
		|| !(v = get_param_line(data, key)))
		return (NULL);
	return (ft_strchr(*v, '=') + 1);
}

char	**get_param_line(t_data *data, char *key)
{
	char	**v;

	if (!key || !*key)
		return (NULL);
	v = NULL;
	if (!(v = get_keyval(data->env, key)))
		if (!(v = get_keyval(data->loc, key)))
			v = get_keyval(data->spe, key);
	return (v);
}
