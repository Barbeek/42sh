/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolff <hwolff@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 14:09:13 by hben-yah          #+#    #+#             */
/*   Updated: 2019/03/27 18:27:24 by hwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

/*
**http://pubs.opengroup.org/onlinepubs/9699919799/utilities/V3_chap02.html#unset
*/

int		sh_unset(t_data *data, int ac, char **av)
{
	int		i;

	if (ac < 2)
		return (put_error2(OK, "unset", "not enough arguments"));
	i = 1;
	if (ft_strcmp(av[i], "PATH") == 0)
		empty_hash(data->hashtable);
	while (i < ac)
	{
		unset_val(&data->env, av[i]);
		unset_val(&data->loc, av[i]);
		++i;
	}
	return (OK);
}
