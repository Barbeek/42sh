/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_pipe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndubouil <ndubouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 18:11:25 by ndubouil          #+#    #+#             */
/*   Updated: 2019/03/26 20:58:13 by ndubouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void	init_pipe(t_list *tmp, int (*fds)[2], int (*pip)[2])
{
	if (tmp->next)
	{
		pipe(*pip);
		(*fds)[1] = (*pip)[1];
	}
	else
	{
		(*pip)[1] = 999;
		(*pip)[0] = 986;
		(*fds)[1] = 1;
	}
}

void		routine_pipe(t_pipeline *pipeline)
{
	int				pip[2];
	int				fds[2];
	t_list			*tmp;

	fds[0] = 0;
	tmp = pipeline->pipeline;
	while (tmp)
	{
		init_pipe(tmp, &fds, &pip);
		if (!routine_fork(pipeline, tmp, fds, pip))
			return ;
		if (fds[0] != 0)
			close(fds[0]);
		if (fds[1] != 1)
			close(fds[1]);
		if (tmp->next)
			fds[0] = pip[0];
		tmp = tmp->next;
		update_status();
	}
}
