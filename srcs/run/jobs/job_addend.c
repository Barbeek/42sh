/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   job_addend.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndubouil <ndubouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 17:36:29 by ndubouil          #+#    #+#             */
/*   Updated: 2019/03/08 15:38:02 by aroblin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	job_addend(t_job **job, t_job *new)
{
	t_job	*tmp;
	t_job	*first;

	tmp = *job;
	first = *job;
	if (new->id == tmp->id)
		new->id = new->id + 1;
	while (tmp->next)
	{
		if (new->id == tmp->next->id)
			new->id = new->id + 1;
		tmp = tmp->next;
	}
	tmp->next = new;
	*job = first;
}
