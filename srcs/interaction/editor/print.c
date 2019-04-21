/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 16:27:04 by hben-yah          #+#    #+#             */
/*   Updated: 2019/03/29 21:12:02 by aroblin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	putwidecar(t_car *car)
{
	if (car->wide)
		putwidecar(car->wide);
	ft_putchar_fd(car->val, FD_EDL);
}

void	putcarlist(t_car *car)
{
	while (car && car->val)
	{
		if (car->selected)
			tc_standout_on();
		ft_putchar_fd(car->val, FD_EDL);
		if (car->wide)
			putwidecar(car->wide);
		if (car->selected)
			tc_standout_off();
		car = car->next;
	}
}

void	putcarlisttab(t_car **car)
{
	t_car *cara;

	while (car && *car)
	{
		cara = *car;
		while (!cara->val && cara != cara->next)
			cara = cara->next;
		putcarlist(cara);
		ft_putchar_fd('\n', FD_EDL);
		++car;
	}
}

void	update_view(t_edl *edl)
{
	t_car	*first;

	if (edl->bef && edl->bef->val)
		first = edl->bef;
	else
		first = edl->last->next;
	tc_cursor_move(first->h, first->v);
	tc_clear_down();
	putcarlist(first);
	tc_cursor_move(edl->cur->h, edl->cur->v);
}

void	print_edition_line(t_edl *edl)
{
	display_prompt(edl);
	if (edl->last && edl->last->next)
	{
		edl->last->next->h = edl->prompt.h;
		edl->last->next->v = edl->prompt.v;
		set_cars_positions(edl, edl->last->next);
	}
	edl->bef = NULL;
	update_view(edl);
}
