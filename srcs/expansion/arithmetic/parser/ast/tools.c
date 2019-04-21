/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 17:42:09 by hwolff            #+#    #+#             */
/*   Updated: 2019/03/27 19:07:27 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	arith_remove_parentheses(t_token **tok)
{
	t_token *cur;

	if ((*tok)->type == OP_PAR)
	{
		cur = *tok;
		while (cur->next->next)
			cur = cur->next;
		if (cur && cur->next && cur->next->type == CL_PAR)
		{
			token_del(tok);
			token_del(&cur->next);
		}
	}
}
