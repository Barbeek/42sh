/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 17:40:08 by hben-yah          #+#    #+#             */
/*   Updated: 2019/03/23 16:37:37 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int
	walk_word(char **line)
{
	char *begin;

	begin = *line;
	if (**line == '\\')
		++(*line);
	else if (**line == '"')
		*line = walkdoublequote(*line + 1);
	else if (**line == '\'')
		*line = walksimplequote(*line + 1);
	else if (**line == '`')
		*line = walkbacktick(*line + 1);
	else if (**line == '$')
		*line = walkdollar(*line + 1);
	**line && ++(*line);
	return (*line - begin);
}

void
	check_token_words(t_token *token)
{
	t_token *prev;

	prev = NULL;
	while (token)
	{
		if ((!prev || (prev->type != WORD && !is_redir_op(prev->type)))
			&& token->type == WORD && is_assignement(token->val))
			token->type = ASSIGNEMENT;
		else if ((prev && (prev->type == WORD || prev->type == ASSIGNEMENT
			|| is_redir_op(prev->type)))
			&& (token->type == OP_BRA || token->type == CL_BRA
				|| token->type == BANG))
			token->type = WORD;
		prev = token;
		token = token->next;
	}
}
