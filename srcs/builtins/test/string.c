/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pespalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 13:57:07 by pespalie          #+#    #+#             */
/*   Updated: 2019/03/18 13:58:22 by pespalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int	string_equality(char **str)
{
	if (ft_strcmp(str[1], "=") == 0)
	{
		if (ft_strcmp(str[0], str[2]) == 0)
			return (0);
	}
	else
	{
		if (ft_strcmp(str[0], str[2]) != 0)
			return (0);
	}
	return (1);
}

int	test_string(char **str)
{
	if (ft_strcmp(str[1], "=") == 0 || ft_strcmp(str[1], "!=") == 0)
		return (string_equality(str));
	return (1);
}

int	operands_n_and_z(char op, char *str)
{
	if (ft_strlen(str) > 0)
	{
		if (op == 'n')
			return (0);
	}
	else if (ft_strlen(str) == 0 && op == 'z')
		return (0);
	return (1);
}
