/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolff <hwolff@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 14:11:12 by hben-yah          #+#    #+#             */
/*   Updated: 2019/03/29 16:38:18 by hwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		is_type_alias(char *av, t_data *data)
{
	int		i;
	size_t	len;

	i = 0;
	if ((len = ft_strlen(av) == 0))
		return (1);
	if (data->alias)
		while (data->alias[i])
		{
			if (ft_strncmp(av, data->alias[i], len) == 0)
			{
				ft_putstr3_fd(av, " is an alias of ",
					ft_strstr(data->alias[i], "=") + 1, 0);
				ft_putchar('\n');
				return (1);
			}
			i++;
		}
	return (0);
}

int		check_error_flags_type(char *av)
{
	int i;

	i = 1;
	ft_putstr3_fd(""SH_NAME": type: -", &av[i], ": invalid options\n", 2);
	ft_putstr_fd("type: usage: type name [name ...]\n", 2);
	return (0);
}

int		error_type(char *arg)
{
	ft_putstr3_fd(""SH_NAME": type: ", arg, " not found\n", 2);
	return (0);
}
