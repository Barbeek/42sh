/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 18:38:39 by hben-yah          #+#    #+#             */
/*   Updated: 2019/03/08 18:52:48 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		check_is_list(t_data *data, t_token **tok)
{
	t_token *b;

	b = *tok;
	if (!*tok || !check_is_and_or(data, tok))
	{
		*tok = b;
		return (0);
	}
	while ((b = *tok)
		&& check_is_separator_op(tok)
		&& check_is_and_or(data, tok))
		;
	*tok = b;
	return (1);
}
