/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cmd_prefix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 17:56:01 by hben-yah          #+#    #+#             */
/*   Updated: 2019/03/09 13:10:05 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		check_is_cmd_prefix(t_data *data, t_token **tok)
{
	t_token *b;

	b = *tok;
	if (!*tok || (!check_token(tok, ASSIGNEMENT)
		&& !check_is_io_redirect(data, tok)))
	{
		*tok = b;
		return (0);
	}
	while ((b = *tok)
		&& (check_token(tok, ASSIGNEMENT)
			|| check_is_io_redirect(data, tok)))
		;
	*tok = b;
	return (1);
}
