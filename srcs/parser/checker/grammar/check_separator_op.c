/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_separator_op.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 17:54:34 by hben-yah          #+#    #+#             */
/*   Updated: 2019/03/08 18:43:25 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		check_is_separator_op(t_token **tok)
{
	return (*tok && (check_token(tok, AND)
		|| check_token(tok, SEMICOLON)));
}
