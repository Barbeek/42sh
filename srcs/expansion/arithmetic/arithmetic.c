/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arithmetic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolff <hwolff@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 17:42:09 by hwolff            #+#    #+#             */
/*   Updated: 2019/03/30 00:04:12 by hwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

long		arithmetic(t_data *data, char *str)
{
	t_token		*tok;
	t_ast		*ast;
	long		res;

	tok = NULL;
	ast = NULL;
	arith_lexical_analysis(&tok, str);
	is_option_d(data) && print_lex(tok, "ARITH");
	res = 0;
	if (!check_expression(data, str, tok))
	{
		arith_build_ast(data, &ast, &tok);
		if (compute(data, str, ast, &res))
			data->param.cancel = 1;
		astlist_del(&ast);
	}
	else
		tokenlist_del(&tok);
	return (res);
}

void		exp_arithmetic(char **str, t_data *data)
{
	char		*beg;
	char		*end;
	long		res;

	while (data->param.cancel == 0
		&& (beg = ft_strstr(*str, "$(("))
		&& *(end = walkparenthese(beg + 2)))
	{
		ft_memset((void *)beg, 0, 3);
		ft_memset((void *)end - 1, 0, 2);
		beg = try_m(ft_strdup(beg + 3));
		exp_arithmetic(&beg, data);
		res = arithmetic(data, beg);
		ft_strdel(&beg);
		beg = try_m(ft_ltoa(res));
		*str = try_m(ft_strjoin3fs(*str, beg, end + 1, FT_ARG1 | FT_ARG2));
	}
}
