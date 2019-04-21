/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctlr_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 16:23:00 by hben-yah          #+#    #+#             */
/*   Updated: 2019/03/19 15:14:14 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	do_ctrl_d(t_data *data)
{
	if (!data->edl.last->next->val)
	{
		if (data->edl.incomp_type == INC_EMPTY
			|| data->edl.incomp_type == COMPLETE)
		{
			ft_putendl_fd("exit", FD_ERR);
			shell_exit(OK);
		}
		data->edl.eof = 1;
	}
	else
		do_delete(data);
}
