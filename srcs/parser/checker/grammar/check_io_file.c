/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_io_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 17:55:21 by hben-yah          #+#    #+#             */
/*   Updated: 2019/03/08 18:52:51 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		check_is_io_file(t_data *data, t_token **tok)
{
	t_token *b;

	b = *tok;
	if (*tok
		&& (check_token(tok, LESS)
			|| check_token(tok, LESSAND)
			|| check_token(tok, GREAT)
			|| check_token(tok, GREATAND)
			|| check_token(tok, DOUBLEGREAT))
		&& check_is_filename(data, tok))
		return (1);
	*tok = b;
	return (0);
}
