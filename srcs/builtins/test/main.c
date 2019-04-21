/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolff <hwolff@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 14:09:13 by hben-yah          #+#    #+#             */
/*   Updated: 2019/03/27 11:54:30 by hwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

/*
**   http://pubs.opengroup.org/onlinepubs/9699919799/utilities/test.html
*/

char		**create_args(char **av, char **new_tab, int j, int i)
{
	char	*tmp;

	while (av[j])
	{
		if (av[j][0] == '=' && av[j - 1][0] == '!')
		{
			tmp = new_tab[1];
			new_tab[1] = ft_strjoin(new_tab[1], av[j]);
			free(tmp);
			i--;
		}
		else
			try_m(new_tab[i] = ft_strdup(av[j]));
		i++;
		j++;
	}
	new_tab[i] = NULL;
	return (new_tab);
}

char		**test_args(size_t ac, char **av)
{
	int		i;
	int		j;
	char	**new_tab;

	i = -1;
	j = 1;
	while (av[1][++i])
		if (av[1][i] == '!')
			return (NULL);
	i = 0;
	if (ft_strcmp(av[j], "!") == 0)
		j = 2;
	if (av[j] == NULL)
		return (NULL);
	try_m(new_tab = (char **)ft_memalloc(sizeof(char *) * ac));
	new_tab = create_args(av, new_tab, j, i);
	return (new_tab);
}

int			one_arg(char **str)
{
	if (str[0])
		return (0);
	return (1);
}

int			negative_res(int res)
{
	int		new_res;

	new_res = 0;
	if (res == 1)
		new_res = 0;
	else if (res == 0)
		new_res = 1;
	return (new_res);
}

int			sh_test(t_data *data, int i, char **arg)
{
	char	**str;
	int		not;
	int		res;

	res = 0;
	not = 0;
	if (ft_strtablen(arg) == 1 && data)
		return (1);
	if (ft_strcmp(arg[1], "!") == 0)
		not = 1;
	str = test_args(ft_strtablen(arg), arg);
	if (str == NULL)
		return (1);
	i = -1;
	while (str[++i])
		;
	if (i > 3)
		ft_putendl("test: too many arguments");
	res = test_parse(str, i);
	if (not == 1)
		res = negative_res(res);
	ft_strtab_del(&str);
	return (res);
}
