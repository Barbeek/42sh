/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_variable.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 17:42:09 by hwolff            #+#    #+#             */
/*   Updated: 2019/03/29 19:25:39 by aroblin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		check_is_variable(t_token **tok)
{
	t_token *b;
	int		i;

	if (!*tok)
		return (0);
	b = *tok;
	i = (check_token(tok, DOUBLEPLUS) || check_token(tok, DOUBLEMINUS));
	if (check_token(tok, VARIABLE))
	{
		if (i == 0)
			check_token(tok, DOUBLEPLUS) || check_token(tok, DOUBLEMINUS);
		return (1);
	}
	*tok = b;
	return (0);
}
