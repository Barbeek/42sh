/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrow_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 16:22:00 by hben-yah          #+#    #+#             */
/*   Updated: 2019/03/23 11:45:59 by pespalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	do_arrow_up(t_data *data)
{
	t_edl	*edl;
	int		j;

	edl = &data->edl;
	leave_select_mode(edl, 0);
	if (edl->hist.cur == 0)
	{
		ft_strdel(&edl->hist.tmpline);
		edl->hist.tmpline = carlist_to_str(data);
		j = edl->hist.count - 1;
	}
	else
		j = edl->hist.cur - 2;
	if (j < 0)
	{
		tc_ring_bell();
		return ;
	}
	edl->hist.cur = j + 1;
	overwrite_editline(edl, edl->hist.list[j]);
}
