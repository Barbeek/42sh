/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sub_expression.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 17:42:09 by hwolff            #+#    #+#             */
/*   Updated: 2019/03/29 19:16:11 by aroblin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		check_is_sub_expression(t_token **tok)
{
	t_token *b;

	if (!*tok)
		return (0);
	b = *tok;
	if (check_token(tok, OP_PAR)
		&& !check_is_expression(tok)
		&& check_token(tok, CL_PAR))
		return (1);
	*tok = b;
	return (0);
}
