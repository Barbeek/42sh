/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_separator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 17:54:27 by hben-yah          #+#    #+#             */
/*   Updated: 2019/03/21 13:28:08 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		check_is_separator(t_token **tok)
{
	t_token *b;

	if (!*tok)
		return (0);
	b = *tok;
	if (check_is_separator_op(tok) && check_is_linebreak(tok))
		return (1);
	*tok = b;
	if (check_is_newline_list(tok))
		return (1);
	*tok = b;
	return (0);
}
