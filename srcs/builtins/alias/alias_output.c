/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alias_output.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 14:11:12 by hben-yah          #+#    #+#             */
/*   Updated: 2019/03/27 12:09:40 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		find_alias(char **alias, char *av)
{
	char	**res;

	if (alias)
	{
		if ((res = get_keyval(alias, av)))
			print_alias(*res);
		else
			return (alias_not_found(av));
	}
	return (OK);
}

void	print_alias(char *alias)
{
	char	**str;
	int		i;

	i = 0;
	try_m(str = ft_strsplit(alias, '='));
	ft_putstr(str[0]);
	ft_putstr("=\'");
	if (str[1])
	{
		while (str[1][i])
		{
			if (str[1][i] == '\'')
			{
				ft_putstr("'\\''");
				i++;
			}
			else
			{
				ft_putchar(str[1][i]);
				i++;
			}
		}
	}
	ft_putendl("\'");
	ft_strtab_del(&str);
}

void	print_alias_lst(char **alias)
{
	if (alias && *alias)
		while (*alias)
			print_alias(*(alias++));
}
