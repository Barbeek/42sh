/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_operator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 17:42:09 by hwolff            #+#    #+#             */
/*   Updated: 2019/03/29 19:24:59 by aroblin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		check_is_comparison_op(t_token **tok)
{
	static int		op[9] = {DOUBLEAND, DOUBLEPIPE, LESSEQUAL,
		GREATEQUAL, DOUBLEEQUAL, BANGEQUAL, LESS, GREAT, 0};
	int				i;

	if (!*tok)
		return (0);
	i = 0;
	while (op[i])
	{
		if (check_token(tok, op[i]))
			return (1);
		++i;
	}
	return (0);
}

int		check_is_calcul_op(t_token **tok)
{
	static int		op[6] = {PLUS, MINUS, STAR, SLASH, PERCENT, 0};
	int				i;

	if (!*tok)
		return (0);
	i = 0;
	while (op[i])
	{
		if (check_token(tok, op[i]))
			return (1);
		++i;
	}
	return (0);
}

int		check_is_operator(t_token **tok)
{
	t_token *b;

	if (!*tok)
		return (0);
	b = *tok;
	if (check_is_calcul_op(tok)
		|| check_is_comparison_op(tok))
		return (1);
	*tok = b;
	return (0);
}
