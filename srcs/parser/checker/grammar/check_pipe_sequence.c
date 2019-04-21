/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pipe_sequence.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 18:37:29 by hben-yah          #+#    #+#             */
/*   Updated: 2019/03/09 13:05:27 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		check_is_pipe_sequence(t_data *data, t_token **tok)
{
	t_token *b;

	b = *tok;
	if (!*tok || !check_is_command(data, tok))
	{
		*tok = b;
		return (0);
	}
	while ((b = *tok)
		&& check_token(tok, PIPE)
		&& check_is_linebreak(tok)
		&& check_is_command(data, tok))
		;
	*tok = b;
	return (1);
}
