/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 17:55:24 by hben-yah          #+#    #+#             */
/*   Updated: 2019/03/29 17:37:15 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	reset_edition_current_line(t_edl *edl)
{
	ft_strdel(&edl->line);
	ft_strdel(&edl->hist.tmpline);
	carlist_del(&edl->last);
	edl->bef = NULL;
	edl->cur = NULL;
	edl->select_ori = NULL;
	edl->len = 0;
	edl->select_mode = 0;
	edl->enter = 0;
}

void	clear_clip(t_edl *edl)
{
	t_car *car;
	t_car *todel;

	car = edl->clip->next;
	while (car->val)
	{
		todel = car;
		car->prev->next = car->next;
		car->next->prev = car->prev;
		car = car->next;
		car_del(&todel);
		car = car->next;
	}
}
