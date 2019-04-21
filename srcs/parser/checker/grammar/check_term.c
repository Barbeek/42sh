/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_term.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 17:58:08 by hben-yah          #+#    #+#             */
/*   Updated: 2019/03/08 18:52:20 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		check_is_term(t_data *data, t_token **tok)
{
	t_token *b;

	b = *tok;
	if (!*tok || !check_is_and_or(data, tok))
	{
		*tok = b;
		return (0);
	}
	while ((b = *tok) && check_is_separator(tok)
		&& check_is_and_or(data, tok))
		;
	*tok = b;
	return (1);
}
