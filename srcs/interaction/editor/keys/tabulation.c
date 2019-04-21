/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tabulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 16:22:00 by hben-yah          #+#    #+#             */
/*   Updated: 2019/03/29 21:12:26 by aroblin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	do_tabulation(t_data *data)
{
	char *line;

	if (!data->edl.cur)
		return ;
	if (data->edl.tabul == 0)
	{
		data->edl.cur->prev->next = NULL;
		line = carlist_to_str(data);
		data->edl.cur->prev->next = data->edl.cur;
		autocomplete(data, &line);
		ft_strdel(&line);
	}
	if (data->edl.tabul == 0 && *data->edl.sugg.list && **data->edl.sugg.list)
	{
		insert_str_to_editline(&data->edl, *data->edl.sugg.list);
		data->edl.tabul = 0;
		update_view(&data->edl);
	}
	else if (data->edl.tabul++ && *(data->edl.sugg.list + 1))
	{
		tc_cursor_move(data->edl.last->h, data->edl.last->v);
		put_suggestions(&data->edl);
		print_edition_line(&data->edl);
	}
}
