/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_subshell.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 17:58:36 by hben-yah          #+#    #+#             */
/*   Updated: 2019/03/08 18:52:22 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		check_is_subshell(t_data *data, t_token **tok)
{
	t_token *b;

	if (!*tok)
		return (0);
	b = *tok;
	if (check_token(tok, OP_PAR) && check_is_compound_list(data, tok)
		&& check_token(tok, CL_PAR))
		return (1);
	*tok = b;
	return (0);
}
