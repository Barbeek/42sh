/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crementation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 17:42:09 by hwolff            #+#    #+#             */
/*   Updated: 2019/03/27 18:42:57 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		compute_crementation(t_data *data, t_ast *ast, long *res)
{
	long	a;

	a = 0;
	if (ast->left)
	{
		if (compute_variable(data, ast->left, &a))
			return (ERROR);
		*res = (ast->token->type == DOUBLEPLUS ? a++ : a--);
		set_var_nbr(data, ast->left->token->val, *res);
	}
	else if (ast->right)
	{
		if (compute_variable(data, ast->right, &a))
			return (ERROR);
		*res = (ast->token->type == DOUBLEPLUS ? ++a : --a);
		set_var_nbr(data, ast->right->token->val, *res);
	}
	return (OK);
}
