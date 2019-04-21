/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 18:50:32 by hben-yah          #+#    #+#             */
/*   Updated: 2019/03/23 11:59:11 by pespalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		check_is_command(t_data *data, t_token **tok)
{
	t_token *b;

	if (!*tok)
		return (0);
	b = *tok;
	if (check_is_simple_command(data, tok))
		return (1);
	*tok = b;
	if (check_is_compound_command(data, tok))
	{
		b = *tok;
		if (!check_is_redirect_list(data, tok))
			*tok = b;
		return (1);
	}
	*tok = b;
	return (0);
}
