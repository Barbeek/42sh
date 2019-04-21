/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pipeline.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 18:37:39 by hben-yah          #+#    #+#             */
/*   Updated: 2019/03/08 18:54:25 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		check_is_pipeline(t_data *data, t_token **tok)
{
	t_token *b;

	if (!*tok)
		return (0);
	b = *tok;
	check_token(tok, BANG);
	if (check_is_pipe_sequence(data, tok))
		return (1);
	*tok = b;
	return (0);
}
