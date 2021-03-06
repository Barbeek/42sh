/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precedence.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 17:42:09 by hwolff            #+#    #+#             */
/*   Updated: 2019/03/29 19:42:44 by aroblin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		arith_get_rank(int type)
{
	if (type == NUMBER || type == VARIABLE
		|| type == OP_PAR)
		return (0);
	if (type == DOUBLEMINUS || type == DOUBLEPLUS)
		return (1);
	if (type == BANG)
		return (2);
	if (type == SLASH || type == PERCENT || type == STAR)
		return (3);
	if (type == MINUS || type == PLUS)
		return (4);
	if (type == LESSEQUAL || type == GREATEQUAL
		|| type == LESS || type == GREAT)
		return (5);
	if (type == BANGEQUAL || type == DOUBLEEQUAL)
		return (6);
	if (type == DOUBLEAND)
		return (7);
	if (type == DOUBLEPIPE)
		return (8);
	return (-1);
}

void	routine_tok(t_token **token, t_token **primary, t_token **primary_prev)
{
	t_token *tmp;

	tmp = NULL;
	while (*token)
	{
		if (arith_get_rank((*token)->type) >= arith_get_rank((*primary)->type)
			&& (((*token)->type != PLUS && (*token)->type != MINUS)
				|| tmp == NULL || tmp->type == VARIABLE
				|| tmp->type == NUMBER || tmp->type == CL_PAR))
		{
			*primary_prev = tmp;
			*primary = *token;
		}
		if ((*token)->type == OP_PAR)
			while (*token && (*token)->type != CL_PAR)
				*token = (*token)->next;
		if (*token)
		{
			tmp = *token;
			*token = (*token)->next;
		}
	}
}

t_token	*arith_get_primary_prev_token(t_token **primary_prev, t_token *token)
{
	t_token *primary;

	if (!token)
		return (NULL);
	primary = token;
	routine_tok(&token, &primary, primary_prev);
	return (primary);
}
