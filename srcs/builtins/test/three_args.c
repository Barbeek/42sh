/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolff <hwolff@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 19:04:26 by hwolff            #+#    #+#             */
/*   Updated: 2019/03/18 14:20:04 by pespalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		error_integer(char *str)
{
	ft_putstr("test: integer expression expected: ");
	ft_putstr(str);
	ft_putchar('\n');
	return (1);
}

int		check_integer(char **str)
{
	int	i;

	i = 0;
	if (!str[0][0] || !str[2][0])
		return (1);
	if (str[0][i] == '-')
		i++;
	while (str[0][i])
	{
		if (ft_isdigit(str[0][i]) == 0)
			return (error_integer(str[0]));
		i++;
	}
	i = 0;
	if (str[2][i] == '-')
		i++;
	while (str[2][i])
	{
		if (ft_isdigit(str[2][i]) == 0)
			return (error_integer(str[2]));
		i++;
	}
	return (0);
}

int		test_arithmetic(char **str)
{
	int	a;
	int	b;

	if (check_integer(str))
		return (1);
	a = ft_atoi(str[0]);
	b = ft_atoi(str[2]);
	if (ft_strcmp(str[1], "-eq") == 0 && a == b)
		return (0);
	if (ft_strcmp(str[1], "-ne") == 0 && a != b)
		return (0);
	if (ft_strcmp(str[1], "-lt") == 0 && a < b)
		return (0);
	if (ft_strcmp(str[1], "-le") == 0 && a <= b)
		return (0);
	if (ft_strcmp(str[1], "-gt") == 0 && a > b)
		return (0);
	if (ft_strcmp(str[1], "-ge") == 0 && a >= b)
		return (0);
	return (1);
}

int		three_args(char **str)
{
	int	i;

	i = 1;
	if (ft_strcmp(str[1], "=") == 0 || ft_strcmp(str[1], "!=") == 0)
		return (test_string(str));
	if (str[1][0] != '-')
	{
		ft_putstr("42sh: condition expected: ");
		ft_putendl(str[1]);
		return (1);
	}
	if (ft_strcmp(str[1], "-eq") == 0 || ft_strcmp(str[1], "-ne") == 0
		|| ft_strcmp(str[1], "-lt") == 0 || ft_strcmp(str[1], "-le") == 0
		|| ft_strcmp(str[1], "-gt") == 0 || ft_strcmp(str[1], "-ge") == 0)
		return (test_arithmetic(str));
	ft_putstr("42sh: parse error: condition expected: ");
	ft_putendl(str[1]);
	return (i);
}
