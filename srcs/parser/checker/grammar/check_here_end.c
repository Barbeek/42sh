/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_here_end.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 17:54:59 by hben-yah          #+#    #+#             */
/*   Updated: 2019/03/29 19:49:24 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		check_is_here_end(t_data *data, t_token **tok)
{
	t_token *b;

	b = *tok;
	if (check_token(tok, WORD))
	{
		get_heredoc(data, b);
		if (data->param.cancel)
			return (0);
		return (1);
	}
	return (0);
}
