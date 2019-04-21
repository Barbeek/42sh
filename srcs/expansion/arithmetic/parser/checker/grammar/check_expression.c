/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_expression.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 17:42:09 by hwolff            #+#    #+#             */
/*   Updated: 2019/03/29 19:13:34 by aroblin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		check_is_expression(t_token **tok)
{
	t_token *b;

	if (!*tok)
		return (1);
	b = *tok;
	if (check_is_operande(tok))
	{
		while ((b = *tok) && (*tok)->type != CL_PAR && (*tok)->type != INVALID)
		{
			if (!check_is_operator(tok))
			{
				*tok = b;
				return (2);
			}
			b = *tok;
			if (!check_is_operande(tok))
			{
				*tok = b;
				return (1);
			}
		}
		return (0);
	}
	*tok = b;
	return (1);
}
