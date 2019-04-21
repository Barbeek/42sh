/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sigwinch.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 18:54:02 by hben-yah          #+#    #+#             */
/*   Updated: 2019/03/29 19:15:05 by pespalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	handle_sigwinch(t_data *data)
{
	struct winsize	ws;

	ioctl(FD_EDL, TIOCGWINSZ, &ws);
	if (data->edl.ncol != ws.ws_col
		|| data->edl.nrow != ws.ws_row)
	{
		data->edl.ncol = ws.ws_col;
		data->edl.nrow = ws.ws_row;
		tc_clear_screen();
		print_edition_line(&data->edl);
		data->edl.bef = NULL;
		update_view(&data->edl);
	}
}
