/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_brace_group.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 18:54:42 by hben-yah          #+#    #+#             */
/*   Updated: 2019/03/08 18:54:55 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		check_is_brace_group(t_data *data, t_token **tok)
{
	t_token *b;

	if (!*tok)
		return (0);
	b = *tok;
	if (check_token(tok, OP_BRA) && check_is_compound_list(data, tok)
		&& check_token(tok, CL_BRA))
		return (1);
	*tok = b;
	return (0);
}
