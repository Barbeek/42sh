/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 17:42:09 by hwolff            #+#    #+#             */
/*   Updated: 2019/03/29 19:13:10 by aroblin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		compute_variable(t_data *data, t_ast *ast, long *res)
{
	char *val;

	val = get_param(data, ast->token->val);
	*res = val ? arithmetic(data, val) : 0;
	return (OK);
}

int		compute_number(t_ast *ast, long *res)
{
	char *s;

	s = ast->token->val;
	if (*s == '0')
	{
		++s;
		if (*s == 'x' || *s == 'X')
			*res = ft_atol_base(++s, 16);
		else if (*s)
			*res = ft_atol_base(s, 8);
		else
			*res = 0;
		return (OK);
	}
	*res = ft_atol_base(s, 10);
	return (OK);
}

int		compute(t_data *data, char *exp, t_ast *ast, long *res)
{
	if (!ast)
		return (OK);
	if (ast->token->type == NUMBER)
		return (compute_number(ast, res));
	if (ast->token->type == VARIABLE)
		return (compute_variable(data, ast, res));
	if (ast->token->type == SLASH
		|| ast->token->type == PERCENT)
		return (compute_division(data, exp, ast, res));
	if (ast->token->type == DOUBLEAND
		|| ast->token->type == DOUBLEPIPE)
		return (compute_logical(data, exp, ast, res));
	if (ast->token->type == DOUBLEPLUS
		|| ast->token->type == DOUBLEMINUS)
		return (compute_crementation(data, ast, res));
	if (ast->token->type == BANG)
		return (compute_inverse(data, exp, ast, res));
	return (compute_operation(data, exp, ast, res));
}
