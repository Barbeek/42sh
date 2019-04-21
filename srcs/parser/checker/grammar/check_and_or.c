/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_and_or.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 18:54:37 by hben-yah          #+#    #+#             */
/*   Updated: 2019/03/23 16:36:39 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		check_is_and_or(t_data *data, t_token **tok)
{
	t_token *b;

	b = *tok;
	if (!*tok || !check_is_pipeline(data, tok))
	{
		*tok = b;
		return (0);
	}
	while ((b = *tok)
		&& (check_token(tok, DOUBLEPIPE) || check_token(tok, DOUBLEAND))
		&& check_is_linebreak(tok)
		&& check_is_pipeline(data, tok))
		;
	*tok = b;
	return (1);
}
