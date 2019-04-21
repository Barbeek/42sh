/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 19:45:59 by hwolff            #+#    #+#             */
/*   Updated: 2019/03/29 21:55:44 by aroblin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void	init_cont(t_edl *edl)
{
	edl->enter = 0;
	edl->eof = 0;
	edl->len = 0;
	edl->hist.cur = 0;
}

int			init_edl(t_edl *edl)
{
	struct winsize	ws;

	ioctl(FD_EDL, TIOCGWINSZ, &ws);
	edl->ncol = ws.ws_col;
	edl->nrow = ws.ws_row;
	if (edl->line)
		overwrite_editline(edl, edl->line);
	else
	{
		edl->last = car_new();
		edl->last->h = edl->prompt.h;
		edl->last->v = edl->prompt.v;
		edl->last->next = edl->last;
		edl->last->prev = edl->last;
	}
	if (!edl->clip)
	{
		edl->clip = car_new();
		edl->clip->next = edl->clip;
		edl->clip->prev = edl->clip;
	}
	edl->cur = edl->last;
	init_cont(edl);
	return (0);
}
