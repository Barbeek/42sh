/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_var.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolff <hwolff@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 08:55:05 by hwolff            #+#    #+#             */
/*   Updated: 2019/03/29 19:46:47 by ndubouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

char	*get_var(t_data *data, char *key)
{
	char	**v;

	if (!key || !*key
		|| !(v = get_param_line(data, key)))
		return (NULL);
	return (ft_strchr(*v, '=') + 1);
}

char	**get_var_line(t_data *data, char *key)
{
	char	**v;

	if (!key || !*key)
		return (NULL);
	if (!(v = get_keyval(data->env, key)))
		v = get_keyval(data->loc, key);
	return (v);
}
