/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_car.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 18:56:36 by hben-yah          #+#    #+#             */
/*   Updated: 2019/03/29 21:22:00 by aroblin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	insert_car(t_car *car, char c)
{
	t_car	*new;

	new = car_new();
	new->val = c;
	if ((car->prev->val & 192) == 192 && (c & 128) == 128)
	{
		new->prev = car->prev;
		new->wide = new->prev->wide;
		new->prev->wide = new;
	}
	else
	{
		new->prev = car->prev;
		new->next = new->prev->next;
		car->prev = new;
		new->prev->next = new;
		new->h = new->next->h;
		new->v = new->next->v;
	}
}

void	insert_car_to_editline(t_edl *edl, char c)
{
	insert_car(edl->cur, c);
	set_cars_positions(edl, edl->cur->prev);
	++edl->len;
}

void	insert_str_to_editline(t_edl *edl, char *str)
{
	while (*str)
		insert_car_to_editline(edl, *(str++));
}

void	overwrite_editline(t_edl *edl, char *line)
{
	t_car	*car;

	carlist_del(&edl->last);
	edl->len = str_to_carlist(&edl->last, line);
	car = edl->last;
	car->next->h = edl->prompt.h;
	car->next->v = edl->prompt.v;
	set_cars_positions(edl, car->next);
	edl->cur = car;
	edl->bef = NULL;
	update_view(edl);
}
