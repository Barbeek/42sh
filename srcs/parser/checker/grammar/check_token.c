/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 18:41:25 by hben-yah          #+#    #+#             */
/*   Updated: 2019/03/29 19:25:08 by pespalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		check_token(t_token **tok, int type)
{
	if (!*tok)
		return (0);
	if ((*tok)->type == type)
	{
		(*tok)->valid = type;
		*tok = (*tok)->next;
		return (1);
	}
	return (0);
}
