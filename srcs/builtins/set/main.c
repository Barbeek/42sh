/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 14:09:13 by hben-yah          #+#    #+#             */
/*   Updated: 2019/03/23 19:14:52 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

/*
**http://pubs.opengroup.org/onlinepubs/9699919799/utilities/V3_chap02.html#set
*/

int		sh_set(t_data *data, int ac, char **av)
{
	if (ac && av)
	{
		ft_putstrtab(data->loc);
		ft_putstrtab(data->env);
	}
	return (OK);
}
