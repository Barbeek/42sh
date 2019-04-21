/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 10:49:42 by hwolff            #+#    #+#             */
/*   Updated: 2019/03/20 14:07:13 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static const char	*g_n[] = {"alias", "bg", "cd", "echo", "exit", "export",
	"fc", "fg", "hash", "jobs", "set", "test", "type", "unalias", "unset", 0};

static int			(*const g_f[])(t_data *, int, char **) = {&sh_alias,
	&sh_bg, &sh_cd, &sh_echo, &sh_exit, &sh_export, &sh_fc, &sh_fg, &sh_hash,
	&sh_jobs, &sh_set, &sh_test, &sh_type, &sh_unalias, &sh_unset, 0};

int		exec_if_builtin(t_data *data, int ac, char **av)
{
	int	i;

	if (data && av && *av && ac > 0)
	{
		i = 0;
		while (g_n[i])
		{
			if (ft_strequ(*av, g_n[i]))
				return ((g_f[i])(data, ac, av));
			++i;
		}
	}
	return (-1);
}

int		is_builtin(char *s)
{
	int	i;

	i = 0;
	while (g_n[i])
		if (ft_strequ(s, g_n[i++]))
			return (1);
	return (0);
}

char	**get_builtins_list(void)
{
	return ((char **)g_n);
}
