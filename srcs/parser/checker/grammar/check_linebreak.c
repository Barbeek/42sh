/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_linebreak.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 17:54:41 by hben-yah          #+#    #+#             */
/*   Updated: 2019/03/21 13:27:48 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		check_is_linebreak(t_token **tok)
{
	t_token *b;

	b = *tok;
	if (check_is_newline_list(tok))
		return (1);
	*tok = b;
	return (1);
}
