/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_io_redirect.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 17:55:27 by hben-yah          #+#    #+#             */
/*   Updated: 2019/03/23 11:58:51 by pespalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		check_is_io_redirect(t_data *data, t_token **tok)
{
	t_token *b;
	t_token *b2;

	if (!*tok)
		return (0);
	b = *tok;
	check_token(tok, IO_NUMBER);
	b2 = *tok;
	if (check_is_io_file(data, tok))
		return (1);
	*tok = b2;
	if (check_is_io_here(data, tok))
		return (1);
	*tok = b;
	return (0);
}
