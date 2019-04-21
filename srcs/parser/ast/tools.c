/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 17:54:30 by hben-yah          #+#    #+#             */
/*   Updated: 2019/03/19 17:12:12 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void
	extract_parentheses(t_token *chosen, t_token **chosen_prev)
{
	t_token *dtok;

	if (chosen->type == OP_PAR)
	{
		dtok = chosen;
		while (dtok->type != CL_PAR)
			dtok = dtok->next;
		if (*chosen_prev)
			(*chosen_prev)->next = dtok->next;
		dtok->next = NULL;
	}
	else if (chosen->type == WORD)
	{
		dtok = chosen;
		while (dtok->next && is_word(dtok->next->type))
			dtok = dtok->next;
		if (*chosen_prev)
			(*chosen_prev)->next = dtok->next;
		dtok->next = NULL;
	}
}
