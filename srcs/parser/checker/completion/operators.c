/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 20:26:46 by hben-yah          #+#    #+#             */
/*   Updated: 2019/03/09 16:50:24 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int
	check_control_op(t_token *token, int type)
{
	while (token)
	{
		if (token->type == type
			&& !get_next_relevant_token(token))
			return (0);
		token = token->next;
	}
	return (1);
}
