/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_redirect_list.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 17:55:36 by hben-yah          #+#    #+#             */
/*   Updated: 2019/03/08 18:52:35 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		check_is_redirect_list(t_data *data, t_token **tok)
{
	t_token *b;

	b = *tok;
	if (!*tok || !check_is_io_redirect(data, tok))
	{
		*tok = b;
		return (0);
	}
	while ((b = *tok) && check_is_io_redirect(data, tok))
		;
	*tok = b;
	return (1);
}
