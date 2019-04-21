/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 14:09:13 by hben-yah          #+#    #+#             */
/*   Updated: 2019/03/23 16:33:12 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

/*
**   http://pubs.opengroup.org/onlinepubs/9699919799/utilities/unalias.html
*/

/*
** Option -a delete tous les alias
*/

static int	unalias_usage(void)
{
	ft_putendl("unalias: usage: unalias [-a] name [name ...]");
	return (1);
}

static int	not_found(char *alias)
{
	ft_putendl3_fd(""SH_NAME": unalias: `", alias,
											"': not found", FD_ERR);
	return (ERROR);
}

int			sh_unalias(t_data *data, int i, char **av)
{
	size_t	len;

	len = 0;
	i = 1;
	if (av[1] == NULL)
		return (unalias_usage());
	if (ft_strequ("-a", av[1]))
	{
		ft_strtabdel(&data->alias);
		data->alias = try_m(ft_strtabnew(0));
		return (0);
	}
	else
	{
		i = 1;
		len = ft_strtablen(data->alias);
		while (av[i])
			unset_val(&data->alias, av[i++]);
	}
	if (len == ft_strtablen(data->alias))
		return (not_found(av[1]));
	return (0);
}
