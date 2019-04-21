/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 17:42:09 by hwolff            #+#    #+#             */
/*   Updated: 2019/03/29 19:12:19 by aroblin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		compute_operation(t_data *data, char *exp, t_ast *ast, long *res)
{
	long	a;

	a = 0;
	if (compute(data, exp, ast->left, res)
			|| compute(data, exp, ast->right, &a))
		return (ERROR);
	if (ast->token->type == PLUS)
		*res += a;
	else if (ast->token->type == MINUS)
		*res -= a;
	else if (ast->token->type == STAR)
		*res *= a;
	else if (ast->token->type == DOUBLEEQUAL)
		*res = (*res == a);
	else if (ast->token->type == BANGEQUAL)
		*res = (*res != a);
	else if (ast->token->type == LESS)
		*res = (*res < a);
	else if (ast->token->type == GREAT)
		*res = (*res > a);
	else if (ast->token->type == GREATEQUAL)
		*res = (*res >= a);
	else if (ast->token->type == LESSEQUAL)
		*res = (*res <= a);
	return (OK);
}

int		compute_division(t_data *data, char *exp, t_ast *ast, long *res)
{
	long	a;

	a = 0;
	if (compute(data, exp, ast->left, res)
		|| compute(data, exp, ast->right, &a) || (a == 0))
		return (arith_div_zero_error(exp, ast->right->token));
	if (ast->token->type == SLASH)
		*res /= a;
	else if (ast->token->type == PERCENT)
		*res %= a;
	return (OK);
}
