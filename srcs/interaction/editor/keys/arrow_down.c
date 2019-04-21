/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrow_down.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 16:22:00 by hben-yah          #+#    #+#             */
/*   Updated: 2019/03/02 20:02:46 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	do_arrow_down(t_data *data)
{
	t_edl	*edl;
	char	*line;
	int		j;

	edl = &data->edl;
	leave_select_mode(&data->edl, 0);
	j = edl->hist.cur;
	if (edl->hist.count == 0 || j == 0)
	{
		edl->hist.cur = 0;
		tc_ring_bell();
		return ;
	}
	else if (j == edl->hist.count)
	{
		line = edl->hist.tmpline;
		edl->hist.cur = 0;
	}
	else
	{
		line = edl->hist.list[j];
		edl->hist.cur = j + 1;
	}
	overwrite_editline(edl, line);
}
