/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 14:11:12 by hben-yah          #+#    #+#             */
/*   Updated: 2019/03/11 17:05:15 by aroblin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static int		is_valid_option(char c, char *options)
{
	if (!ft_isprint(c) || (!ft_strchr(options, c) && c != ' ') || !c)
		return (0);
	return (1);
}

static int		set_options(char *ops, int *options, int pos)
{
	if (ops[pos] == '\0')
		return (0);
	if (is_valid_option(ops[pos], "LP"))
	{
		if (ops[pos] == 'L')
			*options |= (1 << 27);
		else if (ops[pos] == 'P')
			*options |= (1 << 28);
	}
	else
	{
		ft_putstr(""SH_NAME": cd: illegal option --");
		ft_putchar(ops[pos]);
		ft_putendl("\nusage :cd [-LP] [dir]");
		return (0);
	}
	set_options(ops, options, (pos + 1));
	return (1);
}

void			cd_options_parser(char **args, int *options, int *pos_args)
{
	int				i;
	int				takeoptions;

	takeoptions = 1;
	i = 0;
	while (args[++i])
	{
		if (((args[i][0] == '-') && (args[i][1] != '\0')) && takeoptions)
		{
			if (args[i][1] == '-')
				takeoptions = 0;
			else
				set_options(args[i], options, 1);
		}
		else
		{
			*pos_args = i;
			break ;
		}
	}
}
