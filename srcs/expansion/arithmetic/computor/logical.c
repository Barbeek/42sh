/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logical.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 17:42:09 by hwolff            #+#    #+#             */
/*   Updated: 2019/03/23 13:04:55 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		compute_logical(t_data *data, char *exp, t_ast *ast, long *res)
{
	if (compute(data, exp, ast->left, res))
		return (ERROR);
	if ((ast->token->type == DOUBLEPIPE && (*res = (*res != 0)))
		|| (ast->token->type == DOUBLEAND && !(*res = (*res != 0))))
		return (OK);
	if (compute(data, exp, ast->right, res))
		return (ERROR);
	*res = (*res != 0);
	return (OK);
}

int		compute_inverse(t_data *data, char *exp, t_ast *ast, long *res)
{
	if (compute(data, exp, ast->right, res))
		return (ERROR);
	*res = !*res;
	return (OK);
}
