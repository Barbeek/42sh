/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 14:09:13 by hben-yah          #+#    #+#             */
/*   Updated: 2019/03/12 11:34:55 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

/*
**http://pubs.opengroup.org/onlinepubs/9699919799/utilities/V3_chap02.html#exit
*/

int		ft_is_number(char *s)
{
	if (*s && *s != ' ')
	{
		while (*s && *s != ' ')
		{
			if (!ft_isdigit(*s))
				return (0);
			++s;
		}
		return (1);
	}
	return (0);
}

int		sh_exit(t_data *data, int ac, char **av)
{
	int ret;

	ret = OK;
	if (ac > 2)
		return (put_error3(ERROR, "exit", NULL, "too many arguments"));
	else if (ac == 2)
	{
		if (!ft_is_number(av[1]))
			shell_exit(put_error3(255, "exit", av[1],
										"numeric argument required"));
		ret = ft_atoi(av[1]) % 256;
		(ret < 0) && (ret += 256);
		shell_exit(ret);
	}
	else
		shell_exit(data->param.status);
	return (ret);
}
