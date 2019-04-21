/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   completion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 17:49:33 by hben-yah          #+#    #+#             */
/*   Updated: 2019/03/19 17:41:55 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int			check_incomplete_type(t_token *token, int eof)
{
	char	quotetype;

	if (!token)
		return (COMPLETE);
	quotetype = check_quote(token);
	if (quotetype == '"')
		return (INC_DQT);
	if (quotetype == '\'')
		return (INC_SQT);
	if (quotetype == '`')
		return (INC_BTK);
	if (quotetype == '(' || !check_parentheses(token))
		return (INC_PAR);
	if (quotetype == '{' || !check_brackets(token))
		return (INC_BRA);
	if (!check_newline(token) && !eof)
		return (INC_BKS);
	if (!check_control_op(token, PIPE))
		return (INC_PIP);
	if (!check_control_op(token, DOUBLEPIPE))
		return (INC_OR);
	if (!check_control_op(token, DOUBLEAND))
		return (INC_AND);
	return (COMPLETE);
}
