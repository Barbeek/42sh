/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 16:56:22 by hben-yah          #+#    #+#             */
/*   Updated: 2019/03/29 21:19:32 by aroblin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void
	put_entries(t_edl *edl)
{
	char	*ent;
	int		i;
	int		j;

	i = -1;
	while (++i < edl->sugg.nrow)
	{
		j = -1;
		ft_putchar_fd('\n', FD_EDL);
		while (++j < edl->sugg.ncol
			&& ((i + (edl->sugg.nrow * j)) < edl->sugg.len)
			&& (ent = edl->sugg.list[1 + i + (edl->sugg.nrow * j)]))
			ft_putstrrpad_fd(ent, ' ',
				edl->sugg.max + (j < edl->sugg.ncol - 1 ? 1 : 0), FD_EDL);
	}
}

void
	put_suggestions(t_edl *edl)
{
	if (edl->sugg.len > 1 && edl->sugg.list && *edl->sugg.list)
	{
		edl->sugg.ncol = edl->ncol / (edl->sugg.max + 1);
		edl->sugg.ncol = edl->sugg.ncol < 1 ? 1 : edl->sugg.ncol;
		edl->sugg.nrow = (edl->sugg.len / edl->sugg.ncol)
						+ (edl->sugg.len % edl->sugg.ncol != 0);
		edl->sugg.ncol = (edl->sugg.len / edl->sugg.nrow)
						+ (edl->sugg.len % edl->sugg.nrow != 0);
		put_entries(edl);
		ft_putchar_fd('\n', FD_EDL);
	}
}
