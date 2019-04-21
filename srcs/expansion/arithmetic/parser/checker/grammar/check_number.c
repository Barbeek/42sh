/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 17:42:09 by hwolff            #+#    #+#             */
/*   Updated: 2019/03/29 19:18:12 by aroblin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		check_is_number(t_token **tok)
{
	t_token *b;

	if (!*tok)
		return (0);
	b = *tok;
	if (check_token(tok, NUMBER))
	{
		if (!check_number_base(b->val))
			b->valid = INVALID;
		return (1);
	}
	*tok = b;
	return (0);
}

int		check_number_base(char *s)
{
	if (*s == '0')
	{
		++s;
		if (*s == 'x' || *s == 'X')
			return (ft_is_base(16, ++s));
		else if (*s)
			return (ft_is_base(8, s));
		return (1);
	}
	return (ft_is_base(10, s));
}
