/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_io_here.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 17:55:05 by hben-yah          #+#    #+#             */
/*   Updated: 2019/03/08 18:52:50 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		check_is_io_here(t_data *data, t_token **tok)
{
	t_token *b;

	b = *tok;
	if (*tok && check_token(tok, DOUBLELESS)
		&& check_is_here_end(data, tok))
		return (1);
	*tok = b;
	return (0);
}
