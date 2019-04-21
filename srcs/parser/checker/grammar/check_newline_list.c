/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_newline_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 17:54:50 by hben-yah          #+#    #+#             */
/*   Updated: 2019/03/21 13:27:18 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		check_is_newline_list(t_token **tok)
{
	if (!*tok || !check_token(tok, NEWLINE))
		return (0);
	while (check_token(tok, NEWLINE))
		;
	return (1);
}
