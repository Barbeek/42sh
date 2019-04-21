/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precedence.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 17:10:40 by hben-yah          #+#    #+#             */
/*   Updated: 2019/03/29 21:14:38 by ndubouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int			get_rank(int type)
{
	if (type == WORD || type == ASSIGNEMENT
		|| type == OP_PAR || type == CL_PAR
		|| type == OP_BRA || type == CL_BRA)
		return (0);
	if (is_redir_op(type) || type == IO_NUMBER)
		return (1);
	if (type == BANG)
		return (2);
	if (type == PIPE)
		return (3);
	if (type == DOUBLEAND || type == DOUBLEPIPE)
		return (4);
	if (type == SEMICOLON || type == AND || type == NEWLINE)
		return (5);
	return (-1);
}

static void	routine(t_token **primary, t_token **tmp, t_token **primary_prev
	, t_token **token)
{
	int diff;

	diff = get_rank((*token)->type) - get_rank((*primary)->type);
	if (diff > 0
		|| (diff == 0 && ((*token)->type == DOUBLEPIPE
			|| (*token)->type == DOUBLEAND)))
	{
		*primary_prev = *tmp;
		*primary = (*token);
	}
	if ((*token)->type == OP_PAR)
		while (token && (*token)->type != CL_PAR)
			(*token) = (*token)->next;
	if ((*token)->type == OP_BRA)
		while ((*token) && (*token)->type != CL_BRA)
			(*token) = (*token)->next;
	if ((*token))
	{
		*tmp = (*token);
		(*token) = (*token)->next;
	}
}

t_token		*get_primary_prev_token(t_token **primary_prev, t_token *token)
{
	t_token *primary;
	t_token *tmp;

	if (!token)
		return (NULL);
	primary = token;
	tmp = NULL;
	while (token)
		routine(&primary, &tmp, primary_prev, &token);
	return (primary);
}
