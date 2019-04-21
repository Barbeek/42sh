/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 17:42:09 by hwolff            #+#    #+#             */
/*   Updated: 2019/03/29 19:17:42 by aroblin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		arith_div_zero_error(char *expr, t_token *tok)
{
	if (expr)
	{
		ft_putstr2_fd(""SH_NAME": ", expr, FD_ERR);
		ft_putstr_fd(": division by 0 (error token is \"", FD_ERR);
		ft_putendl2_fd(&tok->val[tok->length - 1], "\")\n", FD_ERR);
	}
	return (ERROR);
}

int		arith_value_base_error(t_token *begin, t_token *tok)
{
	ft_putstr_fd(""SH_NAME": ", FD_ERR);
	while (begin && begin != tok)
	{
		ft_putstr2_fd(begin->val, (begin->next ? " " : ""), FD_ERR);
		begin = begin->next;
	}
	ft_putstr_fd(": value too great for base (error token is \"", FD_ERR);
	ft_putendl2_fd(tok->val, "\")\n", FD_ERR);
	return (ERROR);
}

int		arith_syntax_error(char *expr, t_token *tok, int err)
{
	if (expr)
	{
		ft_putstr3_fd(""SH_NAME": ", expr, ": syntax error", FD_ERR);
		ft_putstr2_fd((err == 2 ? " in expression" : ": operand expected"),
			" (error token is \"", FD_ERR);
		while (tok && tok->val)
		{
			ft_putstr2_fd(tok->val, (tok->next ? " " : ""), FD_ERR);
			tok = tok->next;
		}
		ft_putendl_fd("\")\n", FD_ERR);
	}
	return (SYNTAX_ERROR);
}

t_token	*check_expression_lex(t_token *token, int *err)
{
	t_token *t;

	if (!token)
		return (NULL);
	t = token;
	if ((*err = check_is_expression(&t)))
		return (t);
	while (token && token->valid)
	{
		if (token->type == NUMBER && token->valid == INVALID)
		{
			*err = 3;
			return (token);
		}
		token = token->next;
	}
	return (token);
}

int		check_expression(t_data *data, char *expr, t_token *token)
{
	t_token		*error_tok;
	int			err;

	if (!token)
		return (OK);
	err = 0;
	if ((error_tok = check_expression_lex(token, &err)) || err)
	{
		data->param.cancel = 1;
		if (err == 3)
			data->param.status = arith_value_base_error(token, error_tok);
		else
			data->param.status = arith_syntax_error(expr, error_tok, err);
		return (ERROR);
	}
	return (OK);
}
