/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_car.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 12:02:14 by hben-yah          #+#    #+#             */
/*   Updated: 2019/03/03 13:29:19 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	delete_car(t_edl *edl, t_car *car)
{
	if (car->val)
	{
		if (car == edl->cur)
			edl->cur = edl->cur->next;
		car->prev->next = car->next;
		car->next->prev = car->prev;
		car->next->h = car->h;
		car->next->v = car->v;
		set_cars_positions(edl, car->next);
		edl->len -= car_del(&car);
	}
}
