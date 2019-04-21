/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 20:05:00 by hben-yah          #+#    #+#             */
/*   Updated: 2019/03/27 12:06:35 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static int
	set_alias_options(int *options, char *arg)
{
	int index;

	if (*arg == '-')
		++arg;
	while (*arg)
	{
		if ((index = ft_indexof(*arg, ALIAS_OPTIONS)) == -1)
			return (alias_wrong_arg_error(*arg));
		*options |= 1 << index;
		++arg;
	}
	return (OK);
}

int
	check_alias_options(int *options, int ac, char ***av)
{
	int ret;

	++*av;
	while (--ac)
	{
		if (***av == '-' && *(**av + 1))
		{
			if (*(**av + 1) == '-')
			{
				++*av;
				break ;
			}
			if ((ret = set_alias_options(options, **av)))
				return (ret);
		}
		else
			break ;
		++*av;
	}
	return (OK);
}
