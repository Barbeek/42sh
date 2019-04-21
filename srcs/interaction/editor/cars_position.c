/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cars_position.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 11:57:33 by hben-yah          #+#    #+#             */
/*   Updated: 2019/03/24 14:23:11 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	shift_up(t_car *car, int i)
{
	car->v -= i;
	if (i && car->val && car->next)
		shift_up(car->next, i);
}

void	shift_down(t_car *car, int i)
{
	car->v += i;
	if (i && car->val && car->next)
		shift_down(car->next, i);
}

void	scroll_down(t_edl *edl, int i)
{
	tc_scroll_down(i);
	shift_up(edl->last->next, i);
	edl->prompt.v -= i;
}

void	set_cars_positions(t_edl *edl, t_car *cur)
{
	int		h;
	int		v;

	if (!cur)
		return ;
	h = cur->h;
	v = cur->v;
	while (cur->val)
	{
		if (cur->val == '\n')
			(h = -1) && ++v;
		cur = cur->next;
		v = v + ((h + 1) / edl->ncol);
		h = (h + 1) % edl->ncol;
		cur->v = v;
		cur->h = h;
	}
	if ((v = v - edl->nrow + 1) > 0)
		scroll_down(edl, v);
}
