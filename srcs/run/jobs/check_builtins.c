/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_builtins.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 23:45:41 by ndubouil          #+#    #+#             */
/*   Updated: 2019/03/23 16:38:08 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		check_builtins(t_ast *ast)
{
	char	**table;
	int		i;

	tokenlist_to_tab(&table, ast->token);
	i = table ? is_builtin(table[0]) : 0;
	ft_strtabdel(&table);
	return (i);
}
