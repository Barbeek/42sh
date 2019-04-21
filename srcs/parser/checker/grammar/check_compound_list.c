/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_compound_list.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 17:58:30 by hben-yah          #+#    #+#             */
/*   Updated: 2019/03/08 18:52:54 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		check_is_compound_list(t_data *data, t_token **tok)
{
	t_token *b;

	if (!*tok)
		return (0);
	b = *tok;
	if (check_is_linebreak(tok) && check_is_term(data, tok))
	{
		b = *tok;
		if (!check_is_separator(tok))
			*tok = b;
		return (1);
	}
	*tok = b;
	return (0);
}
