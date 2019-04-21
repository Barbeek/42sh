/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_mode.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 14:48:02 by hben-yah          #+#    #+#             */
/*   Updated: 2019/03/29 21:45:43 by aroblin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void		enter_select_mode(t_edl *edl)
{
	if (!edl->select_mode)
	{
		edl->select_mode = 1;
		edl->select_ori = edl->cur;
	}
}

static void	routine_leave(t_car **car, t_car **todel, int delete, t_edl *edl)
{
	if ((*car)->selected)
	{
		if (delete)
		{
			*todel = *car;
			*car = (*car)->next;
			delete_car(edl, *todel);
		}
		else
			(*car)->selected = 0;
	}
}

void		leave_select_mode(t_edl *edl, int delete)
{
	t_car *todel;
	t_car *car;

	if (edl->select_mode)
	{
		car = edl->last->next;
		edl->bef = car;
		while (car->val)
		{
			routine_leave(&car, &todel, delete, edl);
			car = car->next;
		}
		edl->select_mode = 0;
		edl->select_ori = NULL;
		update_view(edl);
	}
}
