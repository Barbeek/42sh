/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_simple_command.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 17:57:31 by hben-yah          #+#    #+#             */
/*   Updated: 2019/03/29 21:36:43 by ndubouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void	cmd_prefix_case(t_data *data, t_token **tok, t_token **b)
{
	*b = *tok;
	if (check_is_cmd_word(tok))
	{
		*b = *tok;
		if (!check_is_cmd_suffix(data, tok))
			*tok = *b;
	}
	else
		*tok = *b;
}

int			check_is_simple_command(t_data *data, t_token **tok)
{
	t_token *b;

	if (!*tok)
		return (0);
	b = *tok;
	if (check_is_cmd_prefix(data, tok))
	{
		cmd_prefix_case(data, tok, &b);
		return (1);
	}
	*tok = b;
	if (check_is_cmd_name(tok))
	{
		b = *tok;
		if (!check_is_cmd_suffix(data, tok))
			*tok = b;
		return (1);
	}
	return (0);
}
