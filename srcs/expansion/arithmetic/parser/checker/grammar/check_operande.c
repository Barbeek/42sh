/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_operande.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 17:42:09 by hwolff            #+#    #+#             */
/*   Updated: 2019/03/29 19:13:49 by aroblin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		check_is_operande(t_token **tok)
{
	t_token *b;
	t_token *c;

	if (!*tok)
		return (0);
	b = *tok;
	check_token(tok, BANG);
	while ((c = *tok)
		&& (check_token(tok, PLUS) || check_token(tok, MINUS)))
		;
	*tok = c;
	if (check_is_number(tok))
		return (1);
	*tok = c;
	if (check_is_variable(tok))
		return (1);
	*tok = c;
	if (check_is_sub_expression(tok))
		return (1);
	*tok = b;
	return (0);
}
