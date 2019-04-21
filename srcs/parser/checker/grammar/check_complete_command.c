/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_complete_command.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 18:38:48 by hben-yah          #+#    #+#             */
/*   Updated: 2019/03/08 18:52:57 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		check_is_complete_command(t_data *data, t_token **tok)
{
	t_token *b;

	if (!*tok)
		return (0);
	b = *tok;
	if (check_is_list(data, tok))
	{
		b = *tok;
		if (!check_is_separator_op(tok))
			*tok = b;
		return (1);
	}
	*tok = b;
	return (0);
}
