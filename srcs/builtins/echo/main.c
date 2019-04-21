/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 14:09:13 by hben-yah          #+#    #+#             */
/*   Updated: 2019/03/13 22:27:52 by ndubouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

/*
**   http://pubs.opengroup.org/onlinepubs/9699919799/
*/

static int		valid_flag_n(char **flag, int *i)
{
	int		j;
	int		state;

	state = 1;
	while (flag[*i])
	{
		j = 0;
		if (flag[*i][j] != '-')
			return (state);
		j = 1;
		while (flag[*i][j])
		{
			if (flag[*i][j] != 'n')
				return (state);
			j++;
		}
		state = 2;
		(*i)++;
	}
	return (state);
}

int				sh_echo(t_data *data, int ac, char **av)
{
	int		i;
	int		flag;

	if (data)
		;
	flag = 1;
	if (ac > 1)
	{
		i = 1;
		flag = valid_flag_n(av, &i);
		while (i < ac)
		{
			ft_putstr(av[i]);
			if (++i < ac)
				ft_putchar(' ');
		}
	}
	if (flag == 1)
		ft_putchar('\n');
	return (OK);
}
