/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brackets.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 20:25:52 by hben-yah          #+#    #+#             */
/*   Updated: 2019/03/09 19:06:45 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int
	check_parentheses(t_token *token)
{
	while (token)
	{
		if (token->type == OP_PAR)
		{
			while (token && token->type != CL_PAR)
				token = token->next;
			if (!token)
				return (0);
		}
		token = token->next;
	}
	return (1);
}

int
	check_brackets(t_token *token)
{
	while (token)
	{
		if (token->type == OP_PAR)
		{
			while (token && token->type != CL_PAR)
				token = token->next;
			if (!token)
				return (0);
		}
		token = token->next;
	}
	return (1);
}
