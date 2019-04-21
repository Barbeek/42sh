/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 22:38:15 by hben-yah          #+#    #+#             */
/*   Updated: 2019/03/19 17:36:10 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static int
	set_options(t_data *data, char *arg)
{
	int index;

	if (*arg == '-')
		++arg;
	while (*arg)
	{
		if ((index = ft_indexof(*arg, SH_OPTIONS)) == -1)
			return (wrong_arg_error(*arg));
		data->param.options |= 1 << index;
		++arg;
	}
	return (OK);
}

int
	check_options(t_data *data, int ac, char **av)
{
	int ret;

	while (ac)
	{
		if (**av == '-' && *(*av + 1))
		{
			if (*(*av + 1) == '-')
				break ;
			if ((ret = set_options(data, *av)))
				return (ret);
		}
		++av;
		--ac;
	}
	return (OK);
}
