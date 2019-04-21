/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newline.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 20:26:26 by hben-yah          #+#    #+#             */
/*   Updated: 2019/03/09 16:52:19 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int
	check_newline(t_token *token)
{
	if (token)
		while (token->next)
			token = token->next;
	return (token && token->type == NEWLINE);
}
