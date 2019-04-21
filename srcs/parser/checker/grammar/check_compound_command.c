/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_compound_command.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 17:58:43 by hben-yah          #+#    #+#             */
/*   Updated: 2019/03/23 11:59:24 by pespalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		check_is_compound_command(t_data *data, t_token **tok)
{
	t_token *b;

	if (!*tok)
		return (0);
	b = *tok;
	if (check_is_brace_group(data, tok))
		return (1);
	*tok = b;
	if (check_is_subshell(data, tok))
		return (1);
	*tok = b;
	return (0);
}
