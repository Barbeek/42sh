/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_var.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 20:21:56 by hben-yah          #+#    #+#             */
/*   Updated: 2019/03/27 12:59:38 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		unset_var(t_data *data, char *key)
{
	int		ret;

	if (!key || !*key)
		return (0);
	ret = unset_val(&data->env, key);
	if (ft_strequ(key, "PATH"))
		empty_hash(data->hashtable);
	ret = unset_val(&data->loc, key);
	return (ret);
}
