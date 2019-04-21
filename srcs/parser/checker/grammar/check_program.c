/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_program.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 17:38:02 by hben-yah          #+#    #+#             */
/*   Updated: 2019/03/21 13:28:43 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		check_is_program(t_data *data, t_token **tok)
{
	t_token *b;

	if (!*tok)
		return (0);
	b = *tok;
	if (check_is_linebreak(tok))
	{
		b = *tok;
		if (!check_is_complete_commands(data, tok)
			|| !check_is_linebreak(tok))
			*tok = b;
		return (1);
	}
	*tok = b;
	return (0);
}
