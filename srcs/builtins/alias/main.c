/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolff <hwolff@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 14:09:13 by hben-yah          #+#    #+#             */
/*   Updated: 2019/03/30 00:12:20 by hwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

/*
**   http://pubs.opengroup.org/onlinepubs/9699919799/utilities/alias.html
*/

int	check_alias(char *alias)
{
	const char	*symb = "><();&/|\\$`\'=\" \n";

	while (*alias && *alias != '=')
	{
		if (ft_strchr(symb, *alias))
			return (alias_invalid_name_error(alias));
		++alias;
	}
	return (OK);
}

int	sh_alias(t_data *data, int ac, char **av)
{
	int		ret;
	int		options;

	if (!(options = 0) && check_alias_options(&options, ac, &av))
		return (MAJOR_ERROR);
	if (ac == 1 || (options & AL_OP_P))
		print_alias_lst(data->alias);
	ret = OK;
	options = 0;
	while (*av)
	{
		if (ft_strchr(*av, '=') && **av != '=')
		{
			if (check_alias(*av))
				ret = ERROR;
			else
				options = set_keyval(&data->alias, *av);
		}
		else
			find_alias(data->alias, *av);
		++av;
	}
	if (options)
		ft_sortstrtab(data->alias);
	return (ret);
}
