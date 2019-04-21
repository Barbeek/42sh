/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolff <hwolff@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 14:11:12 by hben-yah          #+#    #+#             */
/*   Updated: 2019/03/18 14:04:43 by pespalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		check_file_size(char *file)
{
	struct stat	*buf;
	int			size;
	int			i;

	i = 1;
	try_m(buf = malloc(sizeof(struct stat)));
	if (lstat(file, buf) < 0)
	{
		free(buf);
		return (i);
	}
	size = buf->st_size;
	if (size > 0)
		i = 0;
	free(buf);
	return (i);
}

int		check_operands(char op, char *str)
{
	int		i;
	char	*perm;

	i = 1;
	if (op == 'n' || op == 'z')
		i = operands_n_and_z(op, str);
	perm = get_permissions(str);
	if (((op > 'a' && op < 'i') || op == 'L') && perm)
		i = operands_b_to_l(op, perm);
	if (op == 's')
		i = check_file_size(str);
	if ((op == 'p' || op == 'r' || op == 'S' || op == 'u'
		|| op == 'w' || op == 'x') && perm)
		i = rest_of_operands(op, perm);
	ft_memdel((void **)&perm);
	return (i);
}

int		two_args(char **str)
{
	char	op;
	int		i;

	if (ft_strlen(str[0]) > 2)
	{
		ft_putstr("test: unknown condition: ");
		ft_putendl(str[0]);
		return (1);
	}
	if (ft_strlen(str[0]) != 0)
		op = str[0][1];
	if (str[0][0] != '-' || op == 0)
	{
		ft_putstr("42sh: parse error: condition expected: ");
		ft_putendl(str[0]);
		return (1);
	}
	i = check_operands(op, str[1]);
	return (i);
}
