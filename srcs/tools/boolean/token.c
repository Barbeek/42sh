/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_identifier.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 19:39:18 by hben-yah          #+#    #+#             */
/*   Updated: 2019/03/04 16:42:03 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		is_control_op(int token)
{
	return (token == PIPE
		|| token == DOUBLEPIPE
		|| token == DOUBLEAND
		|| token == AND
		|| token == SEMICOLON);
}

int		is_redir_op(int token)
{
	return (token == DOUBLELESS
		|| token == DOUBLEGREAT
		|| token == LESS
		|| token == GREAT
		|| token == GREATAND
		|| token == LESSAND);
}

int		is_unsupported_op(int token)
{
	return (token == TRIPLELESS
		|| token == TRIPLEGREAT
		|| token == DOUBLELESSDASH
		|| token == DOUBLELESSAND
		|| token == DOUBLEGREATAND
		|| token == ANDDOUBLEGREAT
		|| token == ANDDOUBLELESS
		|| token == DOUBLESEMICOLONAND
		|| token == DOUBLESEMICOLON
		|| token == LESSGREAT
		|| token == ANDGREAT
		|| token == ANDLESS
		|| token == GREATPIPE
		|| token == PIPEAND
		|| token == SEMICOLONAND);
}

int		is_word(int token)
{
	return (token == WORD
		|| token == ASSIGNEMENT);
}
