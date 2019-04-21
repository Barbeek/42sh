/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_filename.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 17:55:14 by hben-yah          #+#    #+#             */
/*   Updated: 2019/03/29 19:24:40 by pespalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int	check_is_filename(t_data *data, t_token **tok)
{
	if (data)
		;
	return (*tok && check_token(tok, WORD));
}
