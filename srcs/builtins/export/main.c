/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 14:09:13 by hben-yah          #+#    #+#             */
/*   Updated: 2019/03/26 18:42:52 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

/*
**http://pubs.opengroup.org/onlinepubs/9699919799/utilities/V3_chap02.html
*/

int		sh_export(t_data *data, int ac, char **av)
{
	int		i;
	int		ret;

	i = 1;
	ret = OK;
	while (i < ac)
	{
		if (is_variable_name(av[i]))
			export_var(data, av[i]);
		else
			ret = export_id_error(av[i]);
		++i;
	}
	return (ret);
}
