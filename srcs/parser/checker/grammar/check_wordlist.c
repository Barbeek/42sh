/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wordlist.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 17:57:48 by hben-yah          #+#    #+#             */
/*   Updated: 2019/03/21 13:25:59 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		check_is_wordlist(t_token **tok)
{
	if (!*tok || !check_token(tok, WORD))
		return (0);
	while (check_token(tok, WORD))
		;
	return (1);
}
