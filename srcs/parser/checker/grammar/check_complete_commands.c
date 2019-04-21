/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_complete_commands.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 18:41:35 by hben-yah          #+#    #+#             */
/*   Updated: 2019/03/08 18:52:56 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		check_is_complete_commands(t_data *data, t_token **tok)
{
	t_token *b;

	b = *tok;
	if (!*tok || !check_is_complete_command(data, tok))
	{
		*tok = b;
		return (0);
	}
	while ((b = *tok)
		&& check_is_newline_list(tok)
		&& check_is_complete_command(data, tok))
		;
	*tok = b;
	return (1);
}
