/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cmd_suffix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 17:55:56 by hben-yah          #+#    #+#             */
/*   Updated: 2019/03/09 13:09:47 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		check_is_cmd_suffix(t_data *data, t_token **tok)
{
	t_token *b;

	b = *tok;
	if (!*tok || (!check_token(tok, WORD)
		&& !check_is_io_redirect(data, tok)))
	{
		*tok = b;
		return (0);
	}
	while ((b = *tok)
		&& (check_token(tok, WORD) || check_is_io_redirect(data, tok)))
		;
	*tok = b;
	return (1);
}
